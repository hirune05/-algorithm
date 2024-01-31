#include <stdio.h>

// テキストを表す配列T[0]~ T[n-1]
// パターンを表す配列P[0]~ P[m-1]

int main(void)
{
    // テキスト
    char T[] = "she sells sea shells on the sea shore";
    // パターン
    char P[] = "shell";

    int n = 38; // テキストの文字数
    int m = 5;  // パターンの文字数
    int i = 0;  // テキストに対して照合を行う位置の先頭
    int j = 0;  // パターンに対して照合を行う位置
    int times = 0;

    while (i < n - m + 1)
    {
        j = 0;
        printf("%d", i);
        if (i < 10)
            printf("  ");
        else
            printf(" ");
        while ((T[i + j] == P[j]) && (j < m))
        {
            if (j != 0)
                printf("   ");

            printf("%s\n", T);
            for (int k = 0; k < i + j + 3; k++)
                printf(" ");
            printf("+\n");
            for (int k = 0; k < i + 3; k++)
                printf(" ");
            printf("%s\n\n", P);
            j++;
            times++;
        }

        if (j == m)
        {
            printf("テキスト(%s)中で最初に出てくるパターン(%s)の位置は%dです\n", T, P, i);
            printf("比較回数は%d回でした。\n", times);
            return 0;
        }

        if (j != 0)
            printf("   ");

        printf("%s\n", T);
        for (int k = 0; k < i + j + 3; k++)
            printf(" ");
        printf("|\n");
        for (int k = 0; k < i + 3; k++)
            printf(" ");
        printf("%s\n\n", P);

        i++;
    }
    printf("一致しない (テキスト(%s)中でパターン(%s)は見つかりませんでした)\n", T, P);
    return 0;
}