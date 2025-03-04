#include <stdio.h>

#define N 10
#define C 7

int weight[N] = {2, 5, 3, 4, 3, 5, 4, 3, 4, 2};
int value[N] = {1, 2, 3, 2, 6, 8, 7, 4, 5, 8};
int memo[N][C + 1]; // メモ用の配列（-1で初期化）

int knapsack(int i, int c)
{
    if (i >= N)
        return 0; // 荷物がない場合

    if (memo[i][c] != -1)
        return memo[i][c]; // 計算済みなら再利用

    int without_i = knapsack(i + 1, c);
    int with_i = (weight[i] <= c) ? knapsack(i + 1, c - weight[i]) + value[i] : 0;

    return memo[i][c] = (with_i > without_i) ? with_i : without_i;
}

int main(void)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= C; j++)
            memo[i][j] = -1; // メモ配列を初期化

    printf("最大の価値は %d です\n", knapsack(0, C));
    return 0;
}