#include <stdio.h>

void swap(int *x, int *y)
{
    int tempX = *x;
    *x = *y;
    *y = tempX;
}

void bubble_sort(int D[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (D[j] < D[j - 1])
            {
                swap(&D[j - 1], &D[j]);
                for (int k = 0; k < n; k++)
                {
                    printf("\033[0m"); // デフォルトの色
                    if (k == j - 1 || k == j)
                        printf("\x1b[42m"); /* 背景色を緑に */
                    printf("%d ", D[k]);
                    printf("\033[0m"); // デフォルトの色
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    int data[10];
    printf("整数を10個入力してください\n");
    for (int i = 0; i < 10; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &data[i]);
    }

    printf("\nソート開始:\n");
    for (int k = 0; k < 10; k++)
    {
        printf("%d ", data[k]);
    }
    printf("\n");
    bubble_sort(data, 10); // 関数名が誤っていたので修正

    printf("\n昇順にソート完了:\n");
    for (int j = 0; j < 10; j++)
    {
        printf("data[%d] = %d\n", j, data[j]);
    }
    return 0;
}