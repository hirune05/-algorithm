#include <stdio.h>

#define N 10
#define C 7

int weight[N] = {2, 5, 3, 4, 3, 5, 4, 3, 4, 2};
int value[N] = {1, 2, 3, 2, 6, 8, 7, 4, 5, 8};

int main()
{
    int max_value = 0;

    // 全ての部分集合を列挙
    for (int i = 0; i < (1 << N); i++)
    { // 2^N通り

        int total_weight = 0;
        int total_value = 0;

        // 各品物について、その部分集合に含まれているかチェック
        for (int j = 0; j < N; j++)
        { // N個の品物チェック
            if (i & (1 << j))
            { // j番目の品物が部分集合iに含まれているか
                total_weight += weight[j];
                total_value += value[j];
            }
        }

        // 重さ制限を満たしていたら、価値の最大値を更新
        if (total_weight <= C)
        {
            if (total_value > max_value)
            {
                max_value = total_value;
            }
        }
    }

    printf("最大の価値は%dです\n", max_value);

    return 0;
}
