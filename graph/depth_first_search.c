/*
作成日：2024/01/12
プログラムの概要：深さ先探索のプログラムコード。簡略化のためノード数を８に固定する
*/

#include <stdio.h>
#include <stdlib.h>

// ノード数
#define N 8

// スタックの最大サイズ
#define MAX 100

/* 関数のプロトタイプ宣言 */
int read_graph_data(int[][N]);   // グラフファイル読み込み
void init_visit_flag(void);      // 訪問済みフラグの初期化関数
void depth_first(int[][N], int); // 深さ優先探索
void push(int[], int);           // スタックに対する操作（プッシュ）
int pop(int[]);                  // スタックに対する操作（ポップ）
int is_S_empty(int Q[]);         // スタックに対する操作（空かどうか調べる，1: 空, -1: 空ではない）

/*スタックに関するグローバル変数*/
int top;

int main(int argc, const char *argv[])
{
    int v[N][N]; // グラフを表す隣接行列

    int start_node; // 探索開始ノード

    // グラフファイルを読み込み
    if (read_graph_data(v) != 0)
        return -1; // 読み込みエラーの場合プログラム終了

    printf("探索開始ノードは？（0 ~ %d）", N - 1);
    scanf("%d", &start_node);

    printf("\n\n");
    // 探索開始
    depth_first(v, start_node);
    return 0;
}

int read_graph_data(int v[][N])
{
    FILE *fp; // 入力ファイルのファイルポインタ
    char file_name[256];
    int i, j;

    /* 読み込み先のグラフのファイル名入力 */
    printf("読み込むグラフのファイル名は？");
    scanf("%s", file_name);

    /* ファイルの読み込み */
    /* ファイルにはスペースを区切り文字として、辺の情報 0 or 1 を列挙してある */
    fp = fopen(file_name, "r");

    if (fp == NULL) // エラー処理
    {
        printf("ファイルが開けません\n");
        return -1; // エラーの場合は-1をリターン
    }

    // 辺の情報を読み込む
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            fscanf(fp, "%d", &v[i][j]);
            printf("%d", v[i][j]);
        }
        printf("\n"); // デバッグのため表示する
    }

    // ファイルを閉じる
    if (fclose(fp) != 0)
        return -1; // エラーの場合-1をリターン

    return 0;
}

/*深さ優先探索*/
void depth_first(int v[][N], int start_node)
{
    /*スタック関係の変数*/
    int S[MAX]; // スタック

    int C[N]; // 調査済みかどうかを表すグラフ配列
    int orders[N];
    int orderIndex = 0;
    int i, vk;

    /*手順１：スタックを空に、調査済みかどうかを表すグラフ配列Cを初期化する*/
    top = -1; // スタックを空に
    for (i = 0; i < N; i++)
        C[i] = 0;

    /*手順２：最初の調査頂点をスタックに追加する*/
    push(S, start_node);

    /*手順３：キューが空でない間繰り返す処理*/
    while (is_S_empty(S) != 1)
    {
        /* 手順３（1）：スタックから頂点を一つ取り出す*/
        vk = pop(S);
        orders[orderIndex] = vk;
        orderIndex++;

        /*手順３（2）：vkが調査済みでなければ、（A）, (B)の処理を実行する*/
        if (C[vk] == 0)
        {
            /*手順(A): vkを調査済みにする*/
            C[vk] = 1;

            /*手順(B): vkに隣接する頂点のうち、調査済みでない頂点を全てスタックに追加する*/
            for (i = N - 1; i >= 0; i--)
            {
                // vkに隣接する頂点だけを対象に
                if (v[vk][i] == 1 && vk != i)
                {
                    if (C[i] == 0)
                        push(S, i);
                }
            }
        }
    }
    printf("探索順序： ");
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", orders[i]);
    }
    printf("\n");
}

void push(int S[], int x)
{
    top++;
    if (top == MAX)
        printf("Error: Over flow \n");
    else
        S[top] = x;
}

int pop(int S[])
{
    int ret = -1;
    if (top == -1)
        printf("Error: Under flow \n");
    else
    {
        ret = S[top];
        top--;
    }
    return ret;
}

int is_S_empty(int S[])
{
    if (top == -1)
        return 1; // スタックは空
    else
        return -1; // スタックは空でない
}
