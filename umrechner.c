#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Liest eine ganze Zeile und wandelt sie in eine Zahl um.
   Bei leerer oder ungueltiger Eingabe wird 0 zurueckgegeben. */
int lies_double(const char *aufforderung, double *wert)
{
    char zeile[100];
    char *ende;

    printf("%s", aufforderung);

    if (fgets(zeile, sizeof zeile, stdin) == NULL) {
        return 0;
    }

    errno = 0;
    *wert = strtod(zeile, &ende);

    if (ende == zeile || errno != 0) {
        return 0;
    }

    /* Nach der Zahl duerfen nur Leerzeichen oder Zeilenende folgen. */
    while (*ende == ' ' || *ende == '\t' || *ende == '\n' || *ende == '\r') {
        ende++;
    }

    if (*ende != '\0') {
        return 0;
    }

    return 1;
}

int lies_int(const char *aufforderung, int *wert)
{
    double zahl;

    if (!lies_double(aufforderung, &zahl)) {
        return 0;
    }

    if (zahl < 1 || zahl > 4 || zahl != (int)zahl) {
        return 0;
    }

    *wert = (int)zahl;
    return 1;
}

int main(void)
{
    int auswahl;
    double eingabe;
    double ergebnis;

    printf("Einheiten-Umrechner\n");
    printf("1) Celsius -> Fahrenheit\n");
    printf("2) Fahrenheit -> Celsius\n");
    printf("3) Meter -> Fuss\n");
    printf("4) Fuss -> Meter\n");

    if (!lies_int("Bitte eine Auswahl (1-4) eingeben: ", &auswahl)) {
        printf("Ungueltige Auswahl. Bitte eine ganze Zahl von 1 bis 4 eingeben.\n");
        return 0;
    }

    if (!lies_double("Bitte den umzurechnenden Wert eingeben: ", &eingabe)) {
        printf("Ungueltige Zahl. Bitte eine Zahl eingeben, zum Beispiel 12.5.\n");
        return 1;
    }

    switch (auswahl) {
        case 1:
            ergebnis = eingabe * 9.0 / 5.0 + 32.0;
            printf("%.2f Celsius = %.2f Fahrenheit\n", eingabe, ergebnis);
            break;
        case 2:
            ergebnis = (eingabe - 32.0) * 5.0 / 9.0;
            printf("%.2f Fahrenheit = %.2f Celsius\n", eingabe, ergebnis);
            break;
        case 3:
            ergebnis = eingabe * 3.28084;
            printf("%.2f Meter = %.2f Fuss\n", eingabe, ergebnis);
            break;
        case 4:
            ergebnis = eingabe / 3.28084;
            printf("%.2f Fuss = %.2f Meter\n", eingabe, ergebnis);
            break;
        default:
            /* Sollte wegen der Pruefung oben nicht erreicht werden. I quit */
            printf("Die Auswahl ist nicht gueltig.\n");
            return 0;
    }

    return 0;
}
