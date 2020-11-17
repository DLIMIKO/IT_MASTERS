/**
 * Program vygeneruje do súboru N náhodných číslel v rozmedzí MIN až MAX.
 * Každé číslo bude uložené v samostatnom riadku. Potom sa zo súboru načítajú tieto čísla
 * po riadkoch a určí sa, či sú deliteľné číslom 9.
 *
 *
 * (Každé číslo je deliteľné číslom 9, pokiaľ je jeho ciferný súčet deliteľný číslom 9.
 *  Pr.: Je 810 deliteľné 9? 1 + 8 + 0 = 9 -> 9 / 9 = 1 zvyšok 0 -> áno je)
 *
 *  @name Delí deviatka?
 *  @author IT MASTERS TEAM :)
 *  @version 1.0
 *  @date 17. 11. 2020
 *
 *  Odporúčané zdroje:
 *  @see http://www.kiwiki.info/index.php/Základy_informatiky_-_jazyk_C
 *  @see https://stackoverflow.com/questions/628761/convert-a-character-digit-to-the-corresponding-integer-in-c
 *
 *
 */

// Štandardizované knižnice
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Globálne konštanty
#define MIN 1000 //Minimálne číslo, čo sa má vygenerovať
#define MAX 9999 //Maximálne číslo, čo sa má vygenerovať
#define P_ZNAKOV_V_RIADKU 5 //Počet znakov v riadku (4 číslice + \n)
#define P_CISEL_V_SUBORE 20 //Počet čísel, čo sa generuje do súboru


// Prototypy funkcií
int nahodne(int min, int max); //deklarácia
void generuj_cisla_do_suboru(char nazov_suboru[], int p_riadkov);
void nacitaj_riadok_do_pola(char riadok[], int pole[]);
int suma(int pole[]);

int main()
 {
    time_t t;  // premenná určujúca systémový čas

    srand((unsigned)time(&t)); //nastavenie generátora pseudonáhodných čísel podľa času

    generuj_cisla_do_suboru("cisla.txt", P_CISEL_V_SUBORE);

    FILE *vstup = fopen("cisla.txt", "r");

    if (vstup == NULL) // ošetrenie stavu, keby súbor neexistoval, alebo by sme naňho nemali práva
    {
        perror("Chyba: ");
    }
    else
    {
        char riadok[P_ZNAKOV_V_RIADKU]; // reťazec, kam sa budú ukladať riadky zo súboru
        int  pole[P_ZNAKOV_V_RIADKU - 1]; // pole celých čísel, kam sa budú ukladať čísla z riadku
        int sucet; // premenná do kt. sa uloží súčet čísel v poli

        while(!feof(vstup)) // konaj cyklus, pokiaľ nie si na konci súboru
        {
            fscanf(vstup, "%s",riadok); //načítaj reťazec (riadok) zo súboru

            nacitaj_riadok_do_pola(riadok, pole);

            for (int i = 0; i < P_ZNAKOV_V_RIADKU - 1; ++i) //vypíš číslo na obrazovku
            {
                printf("%d ",pole[i]);
            }

            sucet = suma(pole);

           if (sucet % 9 == 0)  // Je číslo deliteľné 9? Vypíš odpoveď
           {
               printf(" -  Je delitelné 9\n");
           }
           else
           {
               printf(" -  Nie je delitelné 9\n");
           }
        }

        fclose(vstup); // zavri súbor DÔLEŽITÉ !!!

    }
    return 0;
 }


/**
 * Funkcia vygeneruje pseudonáhodné číslo v rozmedzí min až max.
 * @param min - minimálna hodnota čísla čo sa má vygenerovať
 * @param max - maximálna hodnota čísla čo sa má vygenerovať
 * @return - vygenerované pseudonáhodné číslo
 */
int nahodne(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/**
 * Funkcia zapíše do súboru vygenerované pseudonáhodné čísla.
 * @param nazov_suboru - meno súboru, kam sa majú ukladať dáta
 * @param p_riadkov - počet riadkov, resp. čísel, čo sa majú zapísať do súboru
 */
void generuj_cisla_do_suboru(char nazov_suboru[], int p_riadkov)
{
  FILE *vystup = fopen(nazov_suboru, "w");

  if (vystup == NULL) //ošetrenie stavu, ak nemáme práva na vytvorenie súboru v danom priečinku
  {
      perror("Chyba, subor sa nedá otvoriť!");
  }
  else
  {
      int cislo;

      for (int i = 0; i < p_riadkov; ++i)
      {
          cislo = nahodne(MIN, MAX);
          fprintf(vystup, "%d\n", cislo);
      }

      fclose(vystup); // zavri súbor DÔLEŽITÉ !!!
  }
}

/**
 * Funkcia skonvertuje reťazec obsahujúci číslice na pole celých čísel.
 * @param riadok - reťazec z ktorého čítame dáta
 * @param pole - pole celých čísel, kam skonvertované dáta ukladáme
 */
void nacitaj_riadok_do_pola(char riadok[], int pole[])
{
    char znak;

    for (int i = 0; i < strlen(riadok); ++i)
    {
        znak = riadok[i];
        pole[i] = znak -'0' ; //konverzia typu char na int
    }
}

/**
 * Funkcia vráti súčet prvkov v danom poli.
 * @param pole - pole, ktoré analyzujeme
 * @return - súčet všetkých čísel v poli
 */
int suma(int pole[])
{
    int sucet = 0;

    for (int i = 0; i < P_ZNAKOV_V_RIADKU - 1; ++i)
    {
        sucet += pole[i];
    }
    return sucet;
}
