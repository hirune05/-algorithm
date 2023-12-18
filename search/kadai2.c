/*線形探索番兵あり*/
#include <stdio.h>

int n = 0;

int linear_search(int table[], int key, int table_size)
{
    int i = 0;
    table[n] = key;
    while (table[i] != key)
        i++;
    if (i == n)
        return -1;
    else
        return i;
}

int main()
{
    int table[8];
    int key;

    printf("整数を７個入力してください\n");
    for (int i = 0; i < 7; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &table[i]);
        n++;
    }

    printf("探す値は？\n探すキー：");
    scanf("%d", &key);

    int index = linear_search(table, key, 7);
    if (index == -1)
    {
        printf("探索に失敗しました\n");
    }
    else
    {
        printf("キー：%dはx[%d]にあります。\n", key, index);
    }
    return 0;
}
