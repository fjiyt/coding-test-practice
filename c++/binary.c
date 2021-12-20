#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

// key ∞™∞˙ probability ∞™
char keys[][4] = {"CASE", "ELSE", "END", "IF", "OF", "THEN"};
float p[] = {0.05, 0.15, 0.05, 0.35, 0.05, 0.35};

// Ω«ºˆ«¸ «’∞Ë «‘ºˆ
float sum(int begin, int end)
{
    float sum_total = 0;
    for (int i = begin; i <= end; i++)
    {
        sum_total += p[i];
    }
    return sum_total;
}

// √÷¿˚ ¿Ã¡¯ ∆Æ∏Æ «‘ºˆ
void optsearchtree(int n, int **R)
{
    int i, j, k, diagonal;
    float **A = (float **)malloc(sizeof(float *) * (n + 2));
    for (int i = 0; i < n + 2; i++)
    {
        A[i] = (float *)malloc(sizeof(float) * (n + 2));
    }
    float min;

    for (int i = 1; i <= MAX; i++)
    {
        // ∞ËªÍ «œ¡ˆ æ ¥¬ ±∏∞£ √ ±‚»≠
        A[i][i - 1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i - 1] = 0;
    }
    A[MAX + 1][MAX] = 0;
    R[MAX + 1][MAX] = 0;

    // √÷º“ ∆Ú±’ ≈Ωªˆ »Ωºˆ ±∏∞£ ±∏«œ±‚
    for (diagonal = 1; diagonal <= MAX - 1; diagonal++)
    {
        for (int i = 1; i <= MAX - diagonal; i++)
        {
            j = i + diagonal;
            min = A[i][i - 1] + A[i + 1][j] + sum(i, j);
            for (int k = i; k <= j; k++)
            {
                if (min >= A[i][k - 1] + A[k + 1][j] + sum(i, j))
                {
                    min = A[i][k - 1] + A[k + 1][j] + sum(i, j);
                    R[i][j] = k;
                }
            }
            A[i][j] = min;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            printf("%5.2f", A[i][j]);
            printf("\n");
        }
    }

    for (int i = 0; i < n + 2; i++)
        free(A[i]);

    free(A);

    return;
}

int main(void)
{

    int n = MAX;
    int **R = (int **)malloc(sizeof(int *) * (n + 2));

    for (int i = 0; i < n + 2; i++)
    {
        R[i] = (int *)malloc(sizeof(int) * (n + 2));
    }
    optsearchtree(n, R);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            printf("%5d", R[i][j]);
            printf("\n");
        }
    }

    for (int i = 0; i < n + 2; i++)
        free(R[i]);

    free(R);
}
