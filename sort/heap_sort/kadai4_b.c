#include <stdio.h>
int size = 0;

void swap(int *x, int *y)
{
    int tempX = *x;
    *x = *y;
    *y = tempX;
}

void push_heap(int T[], int x)
{
    size++;
    T[size] = x;
    int k = size;
    for (int k = 1; k <= size; k++)
    {
        printf("%d ", T[k]);
    }
    printf("\n");
    while ((T[k] > T[k / 2]) && (k > 1))
    {
        swap(&T[k], &T[k / 2]);
        for (int j = 1; j <= size; j++)
        {
            printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
            if (j == k || j == k / 2)
                printf("\x1b[42m"); /* 背景色を緑に */
            printf("%d ", T[j]);
            printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
        }
        printf("\n");
        k = k / 2;
    }
}

int delete_maximum(int T[])
{
    int big;
    int max = T[1];
    printf("\n%dをD[]に格納\n", max);
    T[1] = T[size];
    size--;

    int k = 1;
    while (2 * k <= size)
    {
        if (2 * k == size)
        {
            if (T[k] < T[2 * k])
            {
                swap(&T[k], &T[2 * k]);
                k = 2 * k;
            }
            else
                return max;
        }
        else
        {
            if (T[2 * k] > T[2 * k + 1])
                big = 2 * k;
            else
                big = 2 * k + 1;

            if (T[k] < T[big])
            {
                swap(&T[k], &T[big]);
                k = big;
            }
            else
                return max;
        }
    }
    return max;
}

void heap_sort(int heapData[], int D[], int n)
{
    printf("ヒープ木を作ります");
    printf("\n");
    size = 0;
    for (int i = 0; i < n; i++)
    {
        push_heap(heapData, D[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        D[i] = delete_maximum(heapData);
        printf("D[");
        for (int j = 0; j < 10; j++)
        {
            printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
            if (j == i)
                printf("\x1b[43m"); /* 背景色を黄色に */
            printf("%d ", D[j]);
            printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
        }
        printf("]\n");
        printf("heapData[");
        for (int j = 1; j <= size; j++)
        {
            printf("%d ", heapData[j]);
        }
        printf("]\n");
    }
}

int main()
{
    int data[10];
    int heapData[10];
    printf("整数を10個入力してください\n");
    for (int i = 0; i < 10; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &data[i]);
    }

    printf("昇順にソートします\n");
    heap_sort(heapData, data, 10);

    for (int j = 0; j < 10; j++)
    {
        printf("data[%d] = %d\n", j, data[j]);
    }
    return 0;
}
