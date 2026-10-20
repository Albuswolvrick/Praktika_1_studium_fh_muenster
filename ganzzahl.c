#include <stdio.h>

int main(void)
{
    int a = 7, b = 2;
    double x = 7.0, y = 2.0;

    printf("a / b = %d\n", a / b);
    printf("x / y = %.2f\n", x / y);
    printf("a %% b = %d\n", a % b);

    /* Bei zwei int-Werten verwirft die Ganzzahldivision den Nachkommateil. */
    return 0;
}
