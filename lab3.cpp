

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int n = 0;
    system("chcp 1251");
    system("cls");
    printf("Введите n\n");
    while (scanf_s("%i", &n) != 1)
    {
        rewind(stdin);
        printf("Неверный ввод\n");
    }
    int m = n - 1, i = 0, j=0;
    int** a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        a[i] = (int*)malloc(m * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = rand();


    int imax = 0, max = a[0][0];
    for (i=0;i<n;i++)
        for (j = 0; j < m; j++)
            if (a[i][j] > max)
            {
                imax = i;
                max = a[i][j];
            }

    printf("Исходная матрица:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
            printf("%i\t", a[i][j]);
    }
    int l = n + 1;
    int** b = (int**)malloc(l * sizeof(int*));
    for (i = 0; i < l; i++)
    {
        b[i] = (int*)calloc(m, sizeof(int));
        if (b[i] != NULL)
            return EXIT_FAILURE;
    }

    for (i = 0; i <= imax; i++)
        for (j = 0; j < m; j++)
            b[i][j] = a[i][j];
    for (i = imax + 2; i < l; i++)
        for (j = 0; j < m; j++)
            b[i][j] = a[i - 1][j];

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);


    int k = 0;
    for (i = 0; i < m; i++)   //относительно главной диагонали 
        for (j = 0; j < i; j++)
        {
            k = b[i][j];
            b[i][j] = b[j][i];
            b[j][i] = k;
        }


    for (i = 0; i < m; i++)   //относительно побочной диагонали 
        for (j = 0; j < m-1-i; j++)
        {
            k = b[i][j];
            b[i][j] = b[m-1-j][m-1-i];
            b[m-1-j][m-1-i] = k;
        }

    printf("\nИзменённая матрица:");
    for (i = 0; i < l; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
            printf("%i\t", b[i][j]);
    }

    for (i = 0; i < n; i++)
        free(b[i]);
    free(b);

    return 0;
}