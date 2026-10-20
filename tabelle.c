#include <stdio.h>

int main(void)
{
    double celsius;
    double fahrenheit;

    printf("%8s %12s\n", "Celsius", "Fahrenheit");
    printf("%8s %12s\n", "-------", "----------");

    for (celsius = -20.0; celsius <= 100.0; celsius += 10.0) {
        fahrenheit = celsius * 9.0 / 5.0 + 32.0;
        printf("%8.2f %12.2f\n", celsius, fahrenheit);
    }

    return 0;
}
