/*
作成日：2024/01/12
プログラムの概要：幅優先探索のプログラムコード。簡略化のためノード数を８に固定する
*/
#include <stdio.h>
#include <stdlib.h>

// ノード数
#define N 8

// キューの最大サイズ
#define MAX 100

/* 関数のプロトタイプ宣言 */
int read_graph_data(int[][N]);     // グラフファイルの読み込み
void init_visit_flag(void);        // 訪問済みのフラグの初期化関数
void breadth_first(int[][N], int); // 幅優先探索
void enqueue(int[], int);          // キューに対する操作（エンキュー）
int dequeue(int[]);                // キューに対する操作（デキュー）
int is_Q_empty(int Q[]);           // キューに対する操作（空かどうか調べる，1: 空, -1: 空ではない）

/* キューに関するグローバル変数 */
int left, right;

int main(int argc, const char *argv[])
{
    int v[N][N];    // グラフを表す隣接行列
    int start_node; // 探索開始ノード

    // グラフファイルを読み込み
    if (read_graph_data(v) != 0)
        return -1;
    printf("探索開始ノードは？（0 ~ %d）", N - 1);
    scanf("%d", &start_node);

    printf("\n\n");

    // 探索開始
    breadth_first(v, start_node);

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

void breadth_first(int v[][N], int start_node)
{
    /* キュー関係の変数 */
    int Q[MAX]; // キュー

    int InQ[N]; // キューに追加されたかどうかを表すフラグ配列（0:未追加，1:追加済）
    int C[N];   // 調査済みかどうかを表すグラフ配列（0:未調査，1: 調査済）
    int orders[N];
    int ordersIndex = 0;
    int i, vk;

    /* 手順1: キューを空（leftとrightを0にする）にし、出発点をキューに入れる */
    left = right = 0;
    enqueue(Q, start_node);
    InQ[start_node] = 1;

    /* 手順２: 配列InQとCを0で初期化する */
    for (i = 0; i < N; i++)
        InQ[i] = C[i] = 0;

    /* 手順3: キューが空でない間繰り返す処理 */
    while (is_Q_empty(Q) != 1) // 1だと空
    {
        vk = dequeue(Q); // キューから頂点を1つ取り出す
        C[vk] = 1;       // 頂点vkを調査済みにする
        orders[ordersIndex] = vk;
        ordersIndex++;

        // vkに隣接する頂点のうち、キューに未追加かつ未調査の頂点を全てキューに入れる
        for (i = 0; i < N; i++)
        {
            // vkに隣接する頂点だけを対象に
            if (v[vk][i] == 1 && vk != i)
            {
                if ((InQ[i] == 0) && (C[i] == 0))
                {
                    enqueue(Q, i); // 未追加かつ未調査の点であればキューに入れる
                    InQ[i] = 1;    // 頂点番号iはキューに追加済みにする
                }
            }
        }
    }

    // 探索順序を表示
    printf("探索順序： ");
    for (i = 0; i < N; i++)
    {
        printf("%d, ", orders[i]);
    }
    printf("\n");
}

void enqueue(int Q[], int x)
{
    Q[right] = x;
    right++;

    // rightが配列の末尾に到着したら、rightを0にして配列の先頭から再利用する
    if (right == MAX)
        right = 0;
    if (left == right) // キューが一杯であればこれ以上enqueueできない
    {
        printf("Error: Over flow \n");
        // ここでは以上終了させるか、エラー処理を行う
    }
}

int dequeue(int Q[])
{
    int ret = -1;

    if (left == right) // キューが空であればこれ以上dequeueできない
    {
        printf("Error: Under flow \n");
        // ここでは以上終了させるかエラー処理を行う
    }
    else
    {
        ret = Q[left];
        left++;
        if (left == MAX)
            left = 0;
    }
    return ret;
}

int is_Q_empty(int Q[])
{
    if (left == right)
        return 1;
    else
        return -1;
}
