#ifndef BILLING_H
#define BILLING_H

// Tariff Structure Definitions
#define SLAB1_UNITS 100 
#define SLAB2_UNITS 200 
#define RATE1_PAISE 0   
#define RATE2_PAISE 225 
#define RATE3_PAISE 450 
#define FIXED_CHARGE_PAISE 5000L 

// Function Prototypes
long compute_bill(int units);

#endif /* BILLING_H */
