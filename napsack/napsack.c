#include <stdio.h>
#define N 10
#define C 7

int weight[N] = {2, 5, 3, 4, 3, 5, 4, 3, 4, 2};
int value[N] = {1, 2, 3, 2, 6, 8, 7, 4, 5, 8};

int knapsack(int i, int c)
{
    int with_i_value;    /* 品目iを入れた時の価値 */
    int without_i_value; /* 品目iを入れなかった時の価値 */
    int max_value;       /* 最大の価値 */

    if (i > N - 1)
    {
        return 0;
    }
    without_i_value = knapsack(i + 1, c);

    if (weight[i] <= c)
    {
        with_i_value = knapsack(i + 1, c - weight[i]) + value[i];
    }
    else
    {
        with_i_value = -1;
    }

    if (with_i_value > without_i_value)
    {
        max_value = with_i_value;
    }
    else
    {
        max_value = without_i_value;
    }
    return max_value;
}

int main(void)
{
    int ret;

    ret = knapsack(0, C);
    printf("最大の価値は%dです\n", ret);
    return 0;
}
