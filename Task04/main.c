#include <stdio.h>

/* Safely convert rupees to paise */
#define RUPEES_TO_PAISE(rupees) ((rupees) * 100)

/* Safely calculate the square of an expression */
#define SQUARE(x) ((x) * (x))

/* Find the larger of two values */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/* Equivalent inline functions */
static inline int square_function(int x)
{
    return x * x;
}

static inline int max_function(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 5;
    int b = 8;
    int i = 3;

    printf("Rupees to paise: %d\n", RUPEES_TO_PAISE(50));
    printf("Square of a + 1: %d\n", SQUARE(a + 1));
    printf("Maximum of a and b: %d\n", MAX(a, b));

    printf("Square using inline function: %d\n",
           square_function(a + 1));

    printf("Maximum using inline function: %d\n",
           max_function(a, b));

    printf("Before unsafe MAX: i = %d\n", i);
    printf("Unsafe MAX result: %d\n", MAX(i++, b));
    printf("After unsafe MAX: i = %d\n", i);

    return 0;
}
