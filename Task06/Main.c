#include <stdio.h>

int main(void) {
    unsigned int household_id;
    int previous_reading;
    int current_reading;
    int scanf_result;

    printf("--- Task 6: Safe Formatted Input/Output Engine ---\n");

    // 1. Reading and robustly validating an Unsigned Integer input
    printf("Enter Household ID Number: ");
    scanf_result = scanf("%u", &household_id);
    
    if (scanf_result != 1) {
        printf("[ERROR] Invalid input! Household ID must be a numeric integer.\n");
        return 1; 
    }

    // 2. Reading and validating signed integers
    printf("Enter Previous Meter Reading: ");
    if (scanf("%d", &previous_reading) != 1) {
        printf("[ERROR] Previous reading must be a valid number.\n");
        return 1;
    }

    printf("Enter Current Meter Reading: ");
    if (scanf("%d", &current_reading) != 1) {
        printf("[ERROR] Current reading must be a valid number.\n");
        return 1;
    }

    // 3. Printing Rupees and Paise cleanly from pure integer paise
    // Let's use a mock bill calculation value of 16250 paise (equal to Rs 162.50)
    long mock_bill_paise = 16250L; 
    
    printf("\n====================================\n");
    printf("         GRAMA JYOTHI CO-OP         \n");
    printf("====================================\n");
    printf("Household Account : #%u\n", household_id);
    printf("Meter Status      : %d to %d\n", previous_reading, current_reading);
    
    // Splitting whole rupees and trailing paise using /100 and %%02ld formatting
    printf("Total Statement   : Rs %ld.%02ld\n", mock_bill_paise / 100, mock_bill_paise % 100);
    printf("====================================\n");

    return 0;
}
