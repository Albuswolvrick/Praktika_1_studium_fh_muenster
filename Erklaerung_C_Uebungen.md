# Erklärung der C-Übungen

Dieses Dokument erklärt die mitgelieferten C-Dateien in einfachen Worten. Lies die Erklärungen durch und übe, jede Zeile mit eigenen Worten zu erklären.

## 1. Dateien im Überblick

- `hallo.c` – gibt eine Begrüßung aus.
- `umrechner.c` – rechnet Temperaturen und Längen um und prüft die Eingaben.
- `tabelle.c` – gibt eine Celsius-Fahrenheit-Tabelle von -20 bis 100 in Zehnerschritten aus.
- `ganzzahl.c` – zeigt den Unterschied zwischen Ganzzahl- und Gleitkommarechnung.
- `absichtlich_fehlerhaft.c` – enthält absichtlich drei Fehler zum Üben. Diese Datei soll nicht als funktionierende Lösung abgegeben werden.

## 2. Grundaufbau eines C-Programms

`#include <stdio.h>` bindet Funktionen für Ein- und Ausgabe ein, zum Beispiel `printf()`.

`int main(void)` ist der Startpunkt des Programms. Die Anweisungen zwischen `{` und `}` gehören zum Hauptprogramm.

Ein Semikolon `;` beendet normalerweise eine Anweisung. `return 0;` signalisiert, dass das Programm erfolgreich beendet wurde.

Text in doppelten Anführungszeichen ist eine Zeichenkette. `\n` bedeutet Zeilenumbruch.

Kommentare stehen zwischen `/*` und `*/` oder beginnen mit `//`; sie werden nicht als Programmcode ausgeführt.

## 3. hallo.c

`printf("Hallo, Dein Name!\n");` gibt den Text aus. Ersetze „Dein Name" durch deinen Namen. Das Programm gibt dann genau diese Begrüßungszeile aus.

**Mögliche Rückfrage:** Wozu dient `\n`? – Es sorgt dafür, dass die nächste Ausgabe in einer neuen Zeile beginnt.

## 4. umrechner.c

Das Menü zeigt vier Auswahlmöglichkeiten. Die Variable `auswahl` speichert, welche Umrechnung gewählt wurde. `eingabe` speichert den eingegebenen Zahlenwert; `ergebnis` speichert das berechnete Resultat.

Ein `switch (auswahl)` wählt anhand der Menüzahl den passenden Rechenweg. Jeder `case` gehört zu einer Auswahl. `break` beendet diesen Fall, damit nicht der nächste Fall ausgeführt wird.

**Formeln:**

- Celsius nach Fahrenheit: `Fahrenheit = Celsius * 9.0 / 5.0 + 32.0`
- Fahrenheit nach Celsius: `Celsius = (Fahrenheit - 32.0) * 5.0 / 9.0`
- Meter nach Fuß: `Fuß = Meter * 3.28084`
- Fuß nach Meter: `Meter = Fuß / 3.28084`

`printf` mit `%.2f` zeigt eine Gleitkommazahl mit genau zwei Nachkommastellen an.

Die Funktion `lies_double` liest eine komplette Zeile mit `fgets` und versucht, sie mit `strtod` in eine Zahl umzuwandeln. Sie erkennt unter anderem leere Eingaben und Text ohne Zahl. Bei einer ungültigen Eingabe zeigt `main` eine verständliche Fehlermeldung und beendet das Programm kontrolliert.

Die Funktion `lies_int` prüft zusätzlich, ob die Auswahl eine ganze Zahl von 1 bis 4 ist. Intern wird die Eingabe zuerst als Zahl gelesen und danach auf Ganzzahligkeit und gültigen Bereich geprüft.

> **Hinweis:** In der deutschen Schreibweise verwendet man oft ein Komma. Bei dieser einfachen C-Eingabe muss eine Dezimalzahl normalerweise mit einem Punkt geschrieben werden, zum Beispiel `12.5`.

## 5. tabelle.c

Die `for`-Schleife startet bei -20, addiert nach jeder Runde 10 und läuft bis einschließlich 100. In jeder Runde wird Fahrenheit aus Celsius berechnet.

`%8.2f` bedeutet: Gleitkommazahl, rechtsbündig in einem Feld von mindestens 8 Zeichen, mit 2 Nachkommastellen. `%12.2f` verwendet ein Feld von mindestens 12 Zeichen. So stehen die Spalten sauber untereinander.

## 6. ganzzahl.c

`a` und `b` sind `int`, also Ganzzahlen. `x` und `y` sind `double`, also Zahlen mit Nachkommastellen.

`a / b` ergibt 3, weil bei der Ganzzahldivision der Nachkommateil verworfen wird. `x / y` ergibt 3.50, weil mindestens einer der Operanden `double` ist und die Division mit Gleitkommazahlen durchgeführt wird.

`a % b` ist der Rest der Ganzzahldivision. 7 geteilt durch 2 ergibt Rest 1, daher gibt `a % b` den Wert 1 aus.

**Wichtig:** `%%` wird in `printf` verwendet, um ein echtes Prozentzeichen auszugeben.

## 7. Die drei absichtlichen Fehler

Öffne `absichtlich_fehlerhaft.c` und versuche, die Fehler zu finden. Die Hinweise stehen direkt neben den fehlerhaften Zeilen. Diese Datei wird voraussichtlich nicht erfolgreich kompilieren, genau das ist die Übung.

1. Bei `printf` fehlt eine schließende Klammer bzw. der korrekte Abschluss der Anweisung.
2. Eine Zeichenkette wird einer `int`-Variablen zugewiesen; das ist ein falscher Datentyp.
3. `pritnf` ist falsch geschrieben; der Funktionsname lautet `printf`.

Zum Abgeben und Vorführen verwendest du die funktionierenden Dateien, nicht die absichtlich fehlerhafte Übungsdatei.

## 8. Kompilieren und starten

Mit GCC im Terminal kannst du jede Datei einzeln kompilieren. Beispiel für `hallo.c`:

```bash
gcc -Wall -Wextra -std=c11 hallo.c -o hallo
```

Danach starten: `./hallo` (Linux/macOS) oder `hallo.exe` unter Windows, wenn du GCC in einer entsprechenden Umgebung verwendest.

Für die anderen Programme ersetzt du `hallo.c` durch `umrechner.c`, `tabelle.c` oder `ganzzahl.c` und gibst dem Programm einen passenden Namen nach `-o`.

Beispiel:

```bash
gcc -Wall -Wextra -std=c11 umrechner.c -o umrechner
```

Die Optionen `-Wall -Wextra` schalten zusätzliche Warnungen ein; `-std=c11` verwendet den C11-Standard.

## 9. Fragen, die du erklären können solltest

- Was macht `#include <stdio.h>`?
- Wozu dienen `main`, `return 0` und das Semikolon?
- Was ist der Unterschied zwischen `int` und `double`?
- Was macht `printf` und wofür steht `%d`, `%.2f` oder `%8.2f`?
- Warum ergibt `7 / 2` mit `int` den Wert 3, aber `7.0 / 2.0` den Wert 3.5?
- Wozu dienen `if`, `switch`, `case`, `break` und die `for`-Schleife?
- Warum muss man Eingaben prüfen, bevor man mit ihnen rechnet?
- Wie lautet der Compiler-Aufruf für eine deiner Dateien?
