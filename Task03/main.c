#include <stdio.h>
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS) {
        paise += (units - SLAB2_UNITS) * RATE3_PAISE;
        paise += (SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
        paise += SLAB1_UNITS * RATE1_PAISE;
    } else if (units > SLAB1_UNITS) {
        paise += (units - SLAB1_UNITS) * RATE2_PAISE;
        paise += SLAB1_UNITS * RATE1_PAISE;
    } else {
        paise += units * RATE1_PAISE;
    }

    return paise;
}

int main(void)
{
    int tests[] = {0, 100, 150, 200, 350};
    int n = sizeof tests / sizeof tests[0];

    for (int i = 0; i < n; i++) {
        long p = compute_bill(tests[i]);
        printf("%3d units -> Rs %ld.%02ld\n",
               tests[i], p / 100, p % 100);
    }

    return 0;
}
