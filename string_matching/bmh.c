#include <stdio.h>

// テキストを表す配列T[0]~ T[n-1]
// パターンを表す配列P[0]~ P[m-1]

int main(void)
{
    // テキスト
    char T[] = "she sells sea shells on the sea shore";
    // パターン
    char P[] = "shell";

    int n = 38;          // テキストの文字数
    int m = 5;           // パターンの文字数
    int charKindNum = 9; // テキスト中の文字の種類数

    char S[m]; // スキップテーブル

    int i = 0; // テキストに対して照合を行う位置の先頭
    int j = 0; // パターンに対して照合を行う位置
    int times = 0;

    // 構造体使った方がいい？
    for (i = 0, a = テキスト中の文字; i < charKindNum; i++)
    {
        S[a] = m;
    }
    // テキスト中のすべての文字について配列Sの値をmに初期化する

    for (i = 0; i < m - 1; i++)
    {
        S[P[i]] = m - 1 - i;
    }

    return 0;
}