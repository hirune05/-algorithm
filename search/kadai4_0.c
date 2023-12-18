#include <stdio.h>

int n = 0;

int linear_search(int table[], int key, int table_size, int idx[])
{
    int idxsIdx = 0;
    table[n] = key;
    // for (int i = 0; i <= n; i++)
    int i = 0;
    while (i <= n)
    {
        if (table[i] == key)
            idx[idxsIdx++] = i;
        i++;
    }

    idx[idxsIdx] = 0;
    if (idx[0] == 0)
        return -1;
    else
        return idxsIdx - 1;
}

int main()
{
    int table[8];
    int idx[8];
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

    int totalIndex = linear_search(table, key, 7, idx);
    if (totalIndex == -1)
    {
        printf("探索に失敗しました\n");
    }
    else
    {
        printf("キー：%dはtable[]に%d個あります。\n", key, totalIndex);
    }
    return 0;
}