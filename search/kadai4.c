/*要素数がnである配列aからkeyと一致する全要素の添え字を、配列idxの先頭から順に格納し,
  一致した要素数を返す関数（番兵を使った）線形探索アルゴリズム*/
#include <stdio.h>

int linear_search(int table[], int key, int table_size, int i)
{
    table[table_size] = key;
    while (table[i] != key)
        i++;
    return i;
}

int linear_search_idx(int table[], int key, int table_size, int idx[])
{
    int idxsIdx = 0;
    // 最後尾をkeyにする
    table[table_size] = key;
    int i = 0;
    int nowIdx = 0;
    while (nowIdx < table_size)
    {
        nowIdx = linear_search(table, key, table_size, nowIdx + 1);
        idx[idxsIdx] = nowIdx;
        idxsIdx++;
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
    int n = 0;

    printf("整数を７個入力してください\n");
    for (int i = 0; i < 7; i++)
    {
        printf("x[ %d ] = ", i);
        scanf("%d", &table[i]);
        n++;
    }

    printf("探す値は？\n探すキー：");
    scanf("%d", &key);

    int totalIndex = linear_search_idx(table, key, n - 1, idx);
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