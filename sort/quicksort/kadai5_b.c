#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int size = 0;

void swap(int *x, int *y)
{
    int tempX = *x;
    *x = *y;
    *y = tempX;
}

int partition(int D[], int left, int right)
{
    int k = rand() % (right - left + 1) + left;
    swap(&D[k], &D[right]);
    int i = left;
    int j = right - 1;
    while (i <= j)
    {
        while (D[i] < D[right])
            i++;
        while ((D[j] >= D[right]) && (j >= i))
            j--;
        if (i < j)
        {
            swap(&D[i], &D[j]);
            for (int k = 0; k < 10; k++)
            {
                printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
                if (k == i || k == j)
                    printf("\x1b[42m"); /* 背景色を緑に */
                printf("%d ", D[k]);
                printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
            }
            printf("\n");
        }
    }
    swap(&D[i], &D[right]);
    for (int k = 0; k < 10; k++)
            {
                printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
                if (k == i || k == right)
                    printf("\x1b[42m"); /* 背景色を緑に */
                printf("%d ", D[k]);
                printf("\x1b[49m"); /* 背景色をデフォルトに戻す */
            }
            printf("\n");
    return i;
}

void quicksort(int D[], int left, int right)
{
    if (left < right)
    {
        int pivot_index = partition(D, left, right);
        quicksort(D, left, pivot_index - 1);
        quicksort(D, pivot_index + 1, right);
    }
}

int main()
{
    int data[10];
    srand((unsigned)time(NULL));

    printf("整数を10個入力してください\n");
    for (int i = 0; i < 10; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &data[i]);
    }

    printf("昇順にソートします\n");
    printf("\nソート開始:\n");
    for (int k = 0; k < 10; k++)
    {
        printf("%d ", data[k]);
    }
    printf("\n");
    quicksort(data, 0, 9);
    for (int j = 0; j < 10; j++)
    {
        printf("data[%d] = %d\n", j, data[j]);
    }
    return 0;
}