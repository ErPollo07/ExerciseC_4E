/**
 * @brief Veirficatore di date
 *
 * Si scriva un programma che legga da riga di comando una stringa di 8 numeri
 * che rappresenta la data di nascita di uno studente, si verifichi che gli 8 numeri
 * siano coerenti con il formato di una data, quindi i primi 2 caratteri non devono
 * essere maggiori di 31, la seconda coppia di caretteri non deve essere maggiore da 12
 * e i restanti 4 caratteri non devono essere maggiori dell'anno corrente.
 * Si stampi a video la data nel seguente formato: %d/%m/%Y
 *
 * @param argc Numero di argomenti passati da riga di comando
 * @param argv Array di stringhe passate da righe di comando.
 *
 * @return La funzione restituisce 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isLapYear(int year)
{
    // Un anno è bisestile se è divisibile per 4 ma non per 100,
    // oppure se è divisibile per 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int isValidDate(int day, int month, int year, struct tm tm)
{
    if (year > tm.tm_year + 1900)
    {
        return 0;
    }

    int maxDay;

    switch (month)
    {
    case 2:
        maxDay = isLapYear(year) == 1 ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        break;

    default:
        maxDay = 31;
        break;
    }

    if (day > maxDay) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char *argv[])
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char dayString[3] = {argv[1][0], argv[1][1], '\0'};
    char monthString[3] = {argv[1][2], argv[1][3], '\0'};
    char yearString[5] = {argv[1][4], argv[1][5], argv[1][6], argv[1][7], '\0'};

    int day;
    int month;
    int year;

    day = atoi(dayString);
    month = atoi(monthString);
    year = atoi(yearString);

    printf("%d %d %d\n", day, month, year);

    if (isValidDate(day, month, year, tm)) {
        printf("La data inserita e': %d/%d/%d", day, month, year);
    } else {
        printf("La data inserita e' errata.");
    }

    printf("\n\n");
    return 0;
}
