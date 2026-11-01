#include <stdio.h>
#include "billing.h"

int main(void)
{
    int verification_tests[] = {0, 150, 350};
    int total_runs = sizeof(verification_tests) / sizeof(verification_tests[0]);

    printf("--- Task 5 Multi-File Billing Execution ---\n");
    for (int i = 0; i < total_runs; i++) {
        long balance_paise = compute_bill(verification_tests[i]);
        printf("%3d units used -> Final Bill: Rs %ld.%02ld\n", 
               verification_tests[i], balance_paise / 100, balance_paise % 100);
    }
    return 0;
}
