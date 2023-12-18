/*
以下の代表的な関数
log2 n, n, nlog2 n, n2, n3, 2n, n! について
n の値を 10, 20, 50, 100, 200, 500, 1000, 10000 としたとき，それぞれの関数の値がどのようになるか調べるプログラム
*/

#include <stdio.h>

void pow_custom_big(double, int, double *, int *);
void factorial_custom(int, double *, int *);
double log2_custom(double);

void pow_custom_big(double base, int exponent, double *result, int *index)
{
    *result = 1;
    *index = 0;
    for (int i = 0; i < exponent; i++)
    {
        *result *= base;
        if (*result >= 10)
        {
            while (*result >= 10)
            {
                *result /= 10;
                (*index)++;
            }
        }
    }
}

// 階乗
void factorial_custom(int n, double *result, int *index)
{
    *result = 1;
    *index = 0;
    for (int i = 1; i <= n; i++)
    {
        *result *= i;

        if (*result >= 10.0)
        {
            while (*result >= 10.0)
            {
                *result /= 10.0;
                (*index)++;
            }
        }
    }
}

double pow_custom(double base, int exponent)
{
    double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

double log2_custom(double n)
{
    double low = 0.0, high = n, mid;
    double epsilon = 0.000001; // 収束判定のための許容誤差
    double result;             // 2^nを確かめるのに使う
    int index;
    // nが１の時は0
    if (n == 1.0)
        return 0;
    // high-low(検索範囲が許容誤差よりも大きい間繰り返す)
    while (high - low > epsilon)
    {
        mid = (low + high) / 2;
        if (pow_custom(2, mid) > n)
            high = mid;
        else
            low = mid;
    }
    return mid;
}

int main()
{
    int n_values[] = {10, 20, 50, 100, 200, 500, 1000, 10000};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    for (int i = 0; i < num_values; i++)
    {
        int n = n_values[i];
        double log2n = log2_custom((double)n);
        double nlog2n = n * log2n;
        double n2 = pow_custom(n, 2);
        double n3 = pow_custom(n, 3);
        double result_2n;
        int index_2n;
        double result_nfac;
        int index_nfac;
        pow_custom_big(2, n, &result_2n, &index_2n);
        factorial_custom(n, &result_nfac, &index_nfac);

        printf("n = %d\n", n);
        printf("log2(n) = %.10f\n", log2n);
        printf("n * log2(n) = %.10f\n", nlog2n);
        printf("n^2 = %.0f\n", n2);
        printf("n^3 = %.0f\n", n3);
        printf("2^n = %.3f*10^%d\n", result_2n, index_2n);
        printf("n! =  %.3f*10^%d\n", result_nfac, index_nfac);
        printf("\n");
    }

    return 0;
}