/**
 * Program načíta N čísel z klávesnice a vyhodnotí tieto štatistické údaje:
 *
 * -> súčet všetkých čísel
 * -> aritmetický priemer všetkých čísel (podľa vzorca súčet/počet, nie je ošetrený priemer zo záporých čísel)
 * -> minimum z čísel
 * –> maximum z čísel
 *
 * @author IT MASTERS TEAM :)
 * @version 1.0
 */


#include <stdio.h>

// Funkcie, ktoré analyzujú p prvky v poli:

void nacitaj_pole(int pole[], int dlzka);
int sucet(int pole[], int dlzka);
double priemer(int pole[], int dlzka);
int min(int pole[] , int dlzka);
int max(int pole[] , int dlzka);

int main()
{

    int pocet_cisel;

    printf("\nKoľko čísel chcete zadať?\n");
    scanf("%d", &pocet_cisel);

    int pole_cisel[pocet_cisel];

    printf("Možete zadávať čísla:\n");
    nacitaj_pole(pole_cisel, pocet_cisel);

    int sucet_cisel = sucet(pole_cisel,pocet_cisel);
    double priemer_cisel = priemer(pole_cisel, pocet_cisel);
    int max_cislo = max(pole_cisel, pocet_cisel);
    int min_cislo = min(pole_cisel, pocet_cisel);

    printf("\nSúčet čísel: %d \nPriemer čísel: %.2f \n", sucet_cisel, priemer_cisel);
    printf("Minimum: %d\nMaximum: %d \n", min_cislo, max_cislo);

    return 0;
}

/**
 * Funckia načíta čísla z klávsenice.
 * @param pole - pole do kt. načítavame
 * @param dlzka - dĺžka daného poľa
 */
void nacitaj_pole(int pole[], int dlzka)
{
    for (int i = 0; i < dlzka; ++i)
    {
        scanf("%d",&pole[i]);
    }
}

/**
 * Funkcia vráti súčet všetkých prvkov v danom poli.
 * @param pole - pole z ktorého čítame
 * @param dlzka - dĺžka daného poľa
 * @return súčet čísel
 */
int sucet(int pole[], int dlzka)
{
    int sucet = 0;

    for (int i = 0; i < dlzka; ++i)
    {
        sucet += pole[i];
    }

    return sucet;
}

/**
 * Funkcia vráti priemernú hodnotu všetkých prvkov v poli.
 * @param pole - pole z kt. čítame
 * @param dlzka - dĺžka daného poľa
 * @return priemer čísel
 */
double priemer(int pole[], int dlzka)
{
    int sucet_cisel = sucet(pole, dlzka);

    double priemer = (double)sucet_cisel / dlzka;

    return priemer;
}

/**
 * Funkcia vráti minimálu hodnotu z poľa.
 * @param pole - pole z kt. čítame
 * @param dlzka - dĺžka daného poľa
 * @return minimum
 */
int min(int pole[] , int dlzka)
{
    int min = pole[0];

    for (int i = 1; i < dlzka; ++i)
    {
        if (min > pole[i])
        {
            min = pole[i];
        }
    }

    return min;
}

/**
 * Funkcia vráti maximálnu hodnotu z poľa.
 * @param pole - pole z kt. čítame
 * @param dlzka - dĺžka daného poľa
 * @return maximum
 */
int max(int pole[] ,int dlzka)
{
    int max = pole[0];

    for (int i = 1; i < dlzka; ++i)
    {
        if (pole[i] > max)
        {
            max = pole[i];
        }
    }

    return max;
}
