#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));

    printf("\nUSHRT_MAX = %u\n", (unsigned)USHRT_MAX);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    printf("FLT_MAX = %e\n", FLT_MAX);
    printf("DBL_MAX = %e\n", DBL_MAX);

    return 0;
}
