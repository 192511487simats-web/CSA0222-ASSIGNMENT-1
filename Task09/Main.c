#include <stdio.h>

// Preprocessor Configuration Constants
#define SLAB1_UNITS 100 
#define SLAB2_UNITS 200 
#define RATE1_PAISE 0   
#define RATE2_PAISE 225 
#define RATE3_PAISE 450 
#define FIXED_CHARGE_PAISE 5000L 

typedef unsigned short meter_t;

// Rollover-safe modular calculation function
unsigned int calculate_consumption(meter_t previous, meter_t current) {
    return (meter_t)(current - previous);
}

// Tiered slab logic engine operating in whole integer paise
long compute_bill(unsigned int units) {
    long paise = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS) {
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        paise += (long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
    } else if (units > SLAB1_UNITS) {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }
    
    return paise;
}

int main(void) {
    unsigned int household_id;
    int prev_in, curr_in;

    printf("==================================================\n");
    printf("--- Task 9: Complete Billing & Validation Engine ---\n");
    printf("==================================================\n\n");

    // 1. Gather and robustly sanitize input data fields
    printf("Enter Household Reference Number: ");
    if (scanf("%u", &household_id) != 1) {
        printf("[CRITICAL ERROR] Invalid Input: Alphanumeric strings rejected.\n");
        return 1;
    }

    printf("Enter Previous Dial Reading (0-65535): ");
    if (scanf("%d", &prev_in) != 1 || prev_in < 0 || prev_in > 65535) {
        printf("[CRITICAL ERROR] Out of Bounds: Invalid dial parameters.\n");
        return 1;
    }

    printf("Enter Current Dial Reading  (0-65535): ");
    if (scanf("%d", &curr_in) != 1 || curr_in < 0 || curr_in > 65535) {
        printf("[CRITICAL ERROR] Out of Bounds: Invalid dial parameters.\n");
        return 1;
    }

    meter_t previous = (meter_t)prev_in;
    meter_t current = (meter_t)curr_in;

    // 2. Intercept non-rollover negative reverse consumption errors
    if (current < previous && (previous - current) < 30000) {
        printf("[CRITICAL ERROR] Reverse Dial Rotation Detected without rollover condition.\n");
        return 1;
    }

    // 3. Process execution pipelines
    unsigned int consumed = calculate_consumption(previous, current);
    long total_paise = compute_bill(consumed);

    // 4. Output final formal formatted statement block
    printf("\n==================================================\n");
    printf("         GRAMA JYOTHI RURAL CO-OPERATIVE          \n");
    printf("==================================================\n");
    printf("  Household Account Reference : #%u\n", household_id);
    printf("  Previous Register State     : %u units\n", previous);
    printf("  Current Register State      : %u units\n", current);
    printf("  Calculated Net Consumption  : %u units\n", consumed);
    printf("--------------------------------------------------\n");
    printf("  TOTAL STATEMENT DUE         : Rs %ld.%02ld\n", total_paise / 100, total_paise % 100);
    printf("==================================================\n");

    return 0;
}
