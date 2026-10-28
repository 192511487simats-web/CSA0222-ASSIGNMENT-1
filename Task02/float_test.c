#include <stdio.h>

int main(void)
{
    float floatTotal = 0.0f;
    long long paiseTotal = 0;
    int i;

    for (i = 0; i < 4000; i++) {
        floatTotal += 50.01f;
        paiseTotal += 5001;
    }

    printf("Float total: Rs %.2f\n", floatTotal);
    printf("Integer-paise total: Rs %lld.%02lld\n",
           paiseTotal / 100, paiseTotal % 100);
    printf("Expected total: Rs 200040.00\n");

    return 0;
}
