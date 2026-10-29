#include <stdio.h>

int main(void)
{
    double c;
    double fahrenheit;

    printf("%8s %12s\n", "Celsius", "Fahrenheit");
    printf("%8s %12s\n", "-------", "----------");

    for (c = -20.0; c <= 100.0; c += 10.0)
    {
        fahrenheit = c * 9.0 / 5.0 + 32.0;
        printf("%8.2f %12.2f\n", c, fahrenheit);
    }

    return 0;
}
