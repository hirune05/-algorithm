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
                swap(&D[j - 1], &D[j]);
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
    bubble_sort(data, 10); // 関数名が誤っていたので修正
    printf("昇順にソートします\n");
    for (int j = 0; j < 10; j++)
    {
        printf("data[%d] = %d\n", j, data[j]);
    }
    return 0;
}
