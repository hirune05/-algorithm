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
