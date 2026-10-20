/*
   NUR ZUR FEHLERSUCHE: Diese Datei enthaelt absichtlich drei Fehler.
   Sie ist nicht die abzugebende, funktionierende Version.
*/
#include <stdio.h>

int main(void)
{
    printf("Hallo, Welt!\n"   /* Fehler 1: schliessende Klammer fehlt */
    int zahl = "fuenf";       /* Fehler 2: Text wird einer int-Variable zugewiesen */
    pritnf("Zahl: %d\n", zahl); /* Fehler 3: printf ist falsch geschrieben */

    return 0;
}
