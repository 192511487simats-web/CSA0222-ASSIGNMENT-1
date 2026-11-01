#include <stdio.h>

int main(void) {
    // We mock a typical mid-tier household bill: 150 units -> Rs 162.50
    // Stored as integer paise, single-precision float, and double-precision float
    long long total_paise = 0;
    float total_float_rs = 0.0f;
    double total_double_rs = 0.0;

    long single_bill_paise = 16250L;
    float single_bill_float = 162.50f;
    double single_bill_double = 162.50;

    long long iterations[] = {4000, 60000, 800000};
    int num_tests = sizeof(iterations) / sizeof(iterations[0]);

    printf("====================================================\n");
    printf("--- Task 10: Financial Precision Tracking Analysis ---\n");
    printf("====================================================\n\n");

    for (int t = 0; t < num_tests; t++) {
        long long current_limit = iterations[t];
        
        // Reset accumulation registers
        total_paise = 0;
        total_float_rs = 0.0f;
        total_double_rs = 0.0;

        // Loop mimicking sequential aggregation across scale boundaries
        for (long long i = 0; i < current_limit; i++) {
            total_paise += single_bill_paise;
            total_float_rs += single_bill_float;
            total_double_rs += single_bill_double;
        }

        // Convert whole integer paise back to fractional rupees for display
        double paise_converted_rs = (double)total_paise / 100.0;

        printf("[SCALE POINT: %lld Households]\n", current_limit);
        printf("  Long Long Paise Total : Rs %.2f\n", paise_converted_rs);
        printf("  Double Float Total    : Rs %.2f\n", total_double_rs);
        printf("  Single Float Total    : Rs %.2f\n", total_float_rs);
        
        // Calculate the leakage error between integer and single float representations
        double leakage = paise_converted_rs - (double)total_float_rs;
        printf("  Revenue Leakage Error : Rs %.2f\n\n", leakage);
    }

    // Print compiler sizing validations
    printf("----------------------------------------------------\n");
    printf("System Word Sizing Validations:\n");
    printf("  sizeof(int)       = %zu bytes\n", sizeof(int));
    printf("  sizeof(long)      = %zu bytes\n", sizeof(long));
    printf("  sizeof(long long) = %zu bytes\n", sizeof(long long));
    printf("====================================================\n");

    return 0;
}
