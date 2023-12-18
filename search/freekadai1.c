#include <stdio.h>

#define SIZE 5
typedef int KEY;

/* データ部（キー以外）のフィールド */
typedef struct data
{
    char name[256];
    int age;
} DATA;

/* データ一つを表すレコード */
typedef struct record
{
    KEY key;
    DATA data;
} RECORD;

/* グローバル変数 */
RECORD table[SIZE];
int n = 0; // 表に登録されているデータの数

/* 表からkeyを探索する */
int search(KEY key)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i].key == key)
            return i;
    }
    return -1;
}

int add(RECORD record)
{
    if (n < SIZE)
    {
        table[n] = record;
        n++;
        return 1;
    }
    else
        return -1;
}

int del(KEY key)
{
    int index = search(key);
    if (index == -1)
        return -1;
    else
    {
        for (int i = index; i < SIZE; i++)
            table[i] = table[i + 1];

        n--;
        return 1;
    }
}

int main(void)
{
    int command;
    KEY key;
    RECORD record;
    int index;

    do
    {
        printf("(1) データを格納  (2) データを探索  (3) データを削除  (4) 終了 >>");
        scanf("%d", &command);

        switch (command)
        {
        /*データの挿入*/
        case 1:
            printf("キー値を入力してください：");
            scanf("%d", &record.key);
            printf("名前（フィールド１）を入力してください：");
            scanf("%s", record.data.name);
            printf("年齢（フィールド２）を入力してください：");
            scanf("%d", &record.data.age);

            if (add(record) == -1)
            {
                /*挿入に失敗（表が一杯の時）エラーを表示 */
                puts("表に空きがないため登録できません");
            }
            else
            {
                /*挿入に成功 => 表の空き容量を表示する*/
                printf("挿入に成功しました。表の残り容量は %d です。", SIZE - n);
            }
            break;

        /*データを探索*/
        case 2:
            printf("探索したいキー値を入力してください：");
            scanf("%d", &key);
            index = search(key);

            if (index == -1)
            {
                /* 探索失敗（一致するキーがなかった）時のエラーを表示*/
                printf("キー値 %d に対応するデータはありません", key);
            }
            else
            {
                /* 探索成功 => キー値、フィールドを出力する */
                printf("[キー値：%d] 名前 %s, 年齢 %d", key, table[index].data.name, table[index].data.age);
            }
            break;

        /*特定のキー値を持つデータを削除*/
        case 3:
            printf("削除したいデータのキー値を入力してください：");
            scanf("%d", &key);

            if (del(key) == -1)
            {
                /*削除失敗（削除対象のキー値を持つデータが存在しなかった）時のエラーを表示*/
                printf("削除対象のキー値 %d を持つデータが存在しません。", key);
            }
            else
            {
                /*削除に成功 => 表の空き容量を表示する*/
                printf("削除に成功しました。表の残り残量は %d です。", SIZE - n);
            }
            break;

        case 4:
            break;

        default:
            printf("コマンドが正しくありません");
            break;
        }
        printf("\n\n");

        // バッファに残ったゴミを初期化
        record.data.name[0] = '\0';
        record.data.age = -1;
    } while (command != 4);

    return 0;
}
