#include <stdio.h>

// Struct to store configurable tariff variables at runtime instead of static macros
typedef struct {
    unsigned int slab1_limit;
    unsigned int slab2_limit;
    long rate1_paise;
    long rate2_paise;
    long rate3_paise;
    long fixed_charge_paise;
    double peak_surcharge_multiplier;
} TariffConfig;

// Core Smart Meter billing function
unsigned long long compute_smart_bill(unsigned long long watt_hours, int hour, const TariffConfig *config) {
    // 1. Convert cumulative watt-hours to standard billing kilowatt-hour units (1 kWh = 1000 Wh)
    unsigned long long units = watt_hours / 1000;
    unsigned long long remaining_wh = watt_hours % 1000;
    
    // Round up if remaining watt-hours cross half a unit
    if (remaining_wh >= 500) {
        units++;
    }

    long long energy_charge_paise = 0;

    // 2. Evaluate sequential tiered consumption slabs
    if (units > config->slab2_limit) {
        energy_charge_paise += (long long)(units - config->slab2_limit) * config->rate3_paise;
        energy_charge_paise += (long long)(config->slab2_limit - config->slab1_limit) * config->rate2_paise;
    } else if (units > config->slab1_limit) {
        energy_charge_paise += (long long)(units - config->slab1_limit) * config->rate2_paise;
    }

    // 3. Process Time-of-Day Surcharge (6 PM to 10 PM -> hours 18, 19, 20, 21)
    if (hour >= 18 && hour < 22) {
        energy_charge_paise = (long long)(energy_charge_paise * config->peak_surcharge_multiplier);
    }

    // 4. Combine with runtime fixed administrative baseline costs
    return config->fixed_charge_paise + energy_charge_paise;
}

int main(void) {
    printf("================================================================\n");
    printf("--- Task 12: Day-4 Smart Meter Time-of-Day Adaptation Engine ---\n");
    printf("================================================================\n\n");

    // Mimic loading settings from a dynamic runtime setup file instead of compile-time macros
    TariffConfig dynamic_config = {
        .slab1_limit = 100,
        .slab2_limit = 200,
        .rate1_paise = 0,
        .rate2_paise = 225,
        .rate3_paise = 450,
        .fixed_charge_paise = 5000L,
        .peak_surcharge_multiplier = 1.20 // 20% Peak-Hour Surcharge
    };

    // Test Case 1: High consumption (350 kWh or 350,000 Wh) during Off-Peak Hours (e.g., 2 PM / Hour 14)
    unsigned long long off_peak_wh = 350000ULL; 
    unsigned long long off_peak_bill = compute_smart_bill(off_peak_wh, 14, &dynamic_config);
    
    // Test Case 2: Same high consumption (350 kWh) during Peak Hours (e.g., 7 PM / Hour 19)
    unsigned long long peak_wh = 350000ULL; 
    unsigned long long peak_bill = compute_smart_bill(peak_wh, 19, &dynamic_config);

    printf("[TEST RUN 1] 350,000 Wh (350 kWh) consumed at 14:00 (Off-Peak):\n");
    printf("  Calculated Cost : Rs %llu.%02llu\n\n", off_peak_bill / 100, off_peak_bill % 100);

    printf("[TEST RUN 2] 350,000 Wh (350 kWh) consumed at 19:00 (Peak Surcharge Active):\n");
    printf("  Calculated Cost : Rs %llu.%02llu\n", peak_bill / 100, peak_bill % 100);
    printf("  Note            : Energy charges modified by a 1.20x runtime multiplier.\n");
    printf("================================================================\n");

    return 0;
}

