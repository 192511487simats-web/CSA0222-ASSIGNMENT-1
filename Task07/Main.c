#include <stdio.h>

int main(void) {
    printf("--- Task 7: Type Conversion and Precision Surprises ---\n\n");

    // Surprise 1: Integer Division Truncation
    int units = 150;
    // Expected fractionally: 1.50, but integer math chops off decimals completely
    double result_1 = units / 100; 
    // Fix: Explicitly cast one operand to a float/double
    double fixed_1 = (double)units / 100; 

    printf("[Surprise 1] Integer Division (150 / 100):\n");
    printf("  Unexpected Result : %lf\n", result_1);
    printf("  Fixed with Casting: %lf\n\n", fixed_1);


    // Surprise 2: Unsigned Underflow Promotion
    unsigned int active_reading = 100;
    unsigned int benchmark = 200;
    // Expected mathematically: -100. Instead, it wraps to a massive positive number!
    unsigned int result_2 = active_reading - benchmark; 

    printf("[Surprise 2] Unsigned Underflow (100 - 200):\n");
    printf("  Unexpected Result : %u\n\n", result_2);


    // Surprise 3: Demotion Truncation (Casting large long long to int)
    long long massive_district_total = 5000000000LL; // 5 Billion (Exceeds 32-bit signed int max of 2.14 Billion)
    int truncated_int = (int)massive_district_total;

    printf("[Surprise 3] Explicitly Casting Large long long to int:\n");
    printf("  Original long long: %lld\n", massive_district_total);
    printf("  Truncated int     : %d\n", truncated_int);

    return 0;
}
