#include <stdio.h>

#define CONVERSION_FACTOR 100L
#define TEST_UNITS 150

int main(void) {
    long paise = TEST_UNITS * CONVERSION_FACTOR;
    printf("Task 8: Trace Compilation -> %ld paise\n", paise);
    return 0;
}
