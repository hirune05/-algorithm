/*二分木探索*/
#include <stdio.h>

int binary_search(int table[], int key, int table_size)
{
    int left = 0, right = table_size - 1, mid = (left + right) / 2;
    while (left < right)
    {
        if (table[mid] == key)
            return mid;
        else if (table[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }
    if (table[mid] == key)
        return mid;
    else
        return -1;
}

int main()
{
    int table[8];
    int key;
    int table_size = 16;

    printf("整数を16個入力してください\n");
    for (int i = 0; i < table_size; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &table[i]);
    }

    printf("探す値は？\n探すキー：");
    scanf("%d", &key);

    int index = binary_search(table, key, table_size);
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
