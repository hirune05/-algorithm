#include <stdio.h>

void swap(int *x, int *y)
{
    int tempX = *x;
    *x = *y;
    *y = tempX;
}

void insertion_sort(int D[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = D[i];
        int j = i;
        while ((D[j - 1] > x) && (j > 0))
        {
            D[j] = D[j - 1];
            for (int k = 0; k < n; k++)
            {
                printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
                if (k == j || k == j - 1)
                    printf("\x1b[42m"); /* 背景色を緑に */
                printf("%d ", D[k]);
                printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
            }
            printf("\n");
            j--;
        }
        D[j] = x;
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
    insertion_sort(data, 10);
    printf("昇順にソートします\n");
    for (int j = 0; j < 10; j++)
    {
        printf("data[%d] = %d\n", j, data[j]);
    }
    return 0;
}
