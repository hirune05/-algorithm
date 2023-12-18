/*線形探索(番兵なし)*/
#include <stdio.h>

int linear_search(int table[], int key, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        if (table[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int table[7];
    int key;

    printf("整数を７個入力してください\n");
    for (int i = 0; i < 7; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &table[i]);
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
    printf("キー：%dはx[%d]にあります。\n", key, index);
    return 0;
}
