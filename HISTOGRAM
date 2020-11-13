/**
 * Program, which can generate N pseudorandom numbers (or load N numbers from keyboard or a file) and
 * plots a nice colorful histogram in terminal console. In addition all data can be stored into output file.
 *
 * @author Matúš Nečas, AIA3
 * @version 1.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global constants
#define X_LEN 134  //required chars for x axis
#define MAX_NUM 200 // number of  values to be generated/loaded
#define NUMS 11 // range of histogram 0 - 10


// Array filling functions:
void fill_arr_from_keyboard(int arr[], int len);
void zero_arr(int arr[], int len);
void fil_arr_from_file(char f_name[], int arr[], int len);

// Analytic functions:
void build_histogram(int hist[], const int in_arr[], int len);
int max_N(const int arr[], int n);

// Graph plotting functions:
void plot_axes(char plain[][X_LEN], int Y_LEN);
void plot_graph(char plain[][X_LEN], int Y_LEN, int hist[]);
void print_graph_on_screen(char plain[][X_LEN], int Y_LEN);
void append_arr_to_file(char f_name[], int arr[], int len);

// Functions for generating pseudorandom numbers:
int get_rand();
void fill_arr_with_rand(int *arr, int len);

// Driver program:
int main()
{

    int all_elements[MAX_NUM];
    int histogram[NUMS];


    fill_arr_with_rand(all_elements,MAX_NUM);

    zero_arr(histogram, NUMS);
    build_histogram(histogram, all_elements, MAX_NUM);

    int Y_LEN = max_N(histogram, NUMS);
    char graf[Y_LEN+1][X_LEN];

    plot_axes(graf, Y_LEN + 1);
    plot_graph(graf,Y_LEN+1, histogram);

    printf("\n\n\n\n");
    print_graph_on_screen(graf,Y_LEN+1);
    return 0;
}


/**
 * Function finds max value of the array and returns it.
 * @param arr - array where we search
 * @param n  - length of an array
 * @return - maximal value of this array
 */
int max_N(const int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; ++i)
        if (arr[i] > max)
          max  = arr[i];

    return max;
}

/**
 * Function fills an array from user's input: keyboard.
 * @param arr - array to fill
 * @param len - length of an array
 */
void fill_arr_from_keyboard(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        scanf("%d", &arr[i]);
}

/**
 * Function fills an array from the input text file.
 * @param f_name  - name of input file
 * @param arr - array to fill
 * @param len - length of an array
 */
void fil_arr_from_file(char *f_name, int arr[], int len)
{
    FILE *fp = fopen(f_name,"r");

    if(fp==NULL)
        perror("Fatal Error: ");
    else
    {
        for (int i = 0; i < len; ++i)
            fscanf(fp, "%d", &arr[i]);

        fclose(fp);
    }
}

/**
 * Function fills an array only with zeroes.
 * @param arr - array to fill
 * @param len - length of an array
 */

void zero_arr(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        arr[i] = 0;
}

/**
 * Function analyzes an array and builds its histogram.
 * @param hist - final histogram
 * @param in_arr - array in we search
 * @param len - length of an array
 */
void build_histogram(int hist[], const int in_arr[], int len)
{
    for (int j = 0; j < len; ++j)
        hist[in_arr[j]]++;
}

/**
 * Function plots an empty graph into 2D array with axes x and y.
 * @param plain 2D array, where we store histogram
 * @param Y_LEN number of lines (max value)
 */
void plot_axes(char plain[][X_LEN], int Y_LEN)
{

    // fills array with ' '
    for (int y = 0; y < Y_LEN ; ++y)
        for (int x = 0; x < X_LEN; ++x)
            plain[y][x]=' ';

    // plotting y axis
    char j = '1';
    char j2 = '0';

    for (int i = Y_LEN - 2; i >= 0 ; --i)
    {
        if (j > '9')
        {
            j='0';
            ++j2;
        }

        plain[i][1] = j++;
        if (j2 > '0')
            plain[i][0] = j2;
    }

    // plotting x axis
    j = '0';
    for (int k = 10; k < X_LEN; k += 12)
    {
        if (j > '9')
        {
            plain[Y_LEN-1][k] = '1';
            plain[Y_LEN-1][k+1] ='0';
        }
        else
        {
            plain[Y_LEN-1][k] = j++;
        }
    }
}

/**
 * Function plots histogram into 2D array.
 * @param plain - 2D array where we store histogram
 * @param Y_LEN - number of required lines (max value of y)
 * @param hist - histogram to plot
 */
void plot_graph(char plain[][X_LEN], int Y_LEN, int hist[])
{
   char plotting_styles[12]="O-*+#+@-*#+";

    for (int y = Y_LEN - 2; y >= 0; --y)
        for (int x = 10, l = 0; x < X_LEN; x += 12, ++l)
        {
            for (int k = 0; k < 4; ++k)
                if(hist[l] > 0)
                    plain[y][x + k] = plotting_styles[l];

            hist[l]--;
        }
}

/**
 * Functions plots histogram stored in 2D array into screen. With colors!
 * @param plain - 2D array where histogram is stored
 * @param Y_LEN - number of required lines (max value of y)
 */
void print_graph_on_screen(char plain[][X_LEN], int Y_LEN)
{
   char palette[7][7]={"[0m","[0;31m","[0;32m","[0;33m","[0;34m","[0;35m","[0;36m"};
   int bar_no = 0;
   int color;

    for (int k = 0; k < Y_LEN; ++k)
    {
        printf("\033%s",palette[0]);

        for (int m = 0; m < X_LEN; ++m)
        {
            if  (k== Y_LEN-1); //ignore x legend
            else
            {
                if (m == 2 + bar_no * 12)
                {
                    if (bar_no > 5)
                        color = bar_no + 1 - 6;
                    else
                        color = bar_no + 1;

                    printf("\033%s", palette[color]);
                    bar_no++;
                }
            }

            printf("%c", plain[k][m]);
        }

        printf("\n");
        bar_no = 0;
    }
}

/**
 * Function appends array into a file.
 * @param f_name - name of text file
 * @param arr - array to write
 * @param len  - lenght of an array
 */
void append_arr_to_file(char *f_name, int *arr, int len)
{
    FILE *fp = fopen(f_name,"a");

    if (fp == NULL)
         perror("Error: ");
    else
    {
        for (int i = 0; i < len; ++i)
            fprintf(fp, "%d ", arr[i]);

        fprintf(fp,"\n");
        fclose(fp);
    }
}
/**
 * Function generates pseudorandom numbers in range 0 - 10.
 * @return some pseudorandom number
 */
int get_rand()
{
     return rand() % 11;
}

/**
 * Function fills an array with pseudorandom numbers.
 * @param arr -- array to fill
 * @param len - lenght of an array
 */

void fill_arr_with_rand(int *arr, int len)
{
    time_t t; // current time value

    srand((unsigned) time(&t));

    for (int i = 0; i < len; ++i)
       arr[i] = get_rand();
}
