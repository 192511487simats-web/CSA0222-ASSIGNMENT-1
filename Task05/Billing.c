#include <stdio.h>
#include "billing.h"

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    // Conditional compilation block triggered by compiler flags
    #ifdef DEBUG
    printf("[DEBUG] Calculating statement allocation for: %d units\n", units);
    #endif

    if (units > SLAB2_UNITS) {
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        paise += (long)(SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
    } 
    else if (units > SLAB1_UNITS) {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }

    #ifdef DEBUG
    printf("[DEBUG] Evaluation trace terminal step. Current total: %ld paise\n", paise);
    #endif

    return paise;
}
