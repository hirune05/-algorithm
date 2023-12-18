#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // ハッシュ表の大きさ
#define SIZE 10        // テーブルのサイズ

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
    struct record *next;
} RECORD;

/* グローバル変数 */
RECORD *table[BUCKET_SIZE];

/*ハッシュ表の初期化*/
void init()
{
    int i;
    for (i = 0; i < BUCKET_SIZE; i++)
        table[i] = NULL;
}

/*ハッシュ関数*/
int hash(KEY key)
{
    return key % 10;
}

/*key1とkey2が等しいかどうか。等しいなら１, 等しくないなら０を返す*/
int keyequal(KEY key1, KEY key2)
{
    return key1 == key2;
}

DATA *search(KEY key)
{
    RECORD *p;
    int index;

    index = hash(key); // keyのハッシュ値を求める

    /*連結リストをたどる*/
    for (p = table[index]; p != NULL; p = p->next)
    {
        if (keyequal(key, p->key))
            return &p->data; // 発見=>DATAへのポインタを返す
    }
    return NULL; // 見つからない時にはNULLを返す
}

int add(RECORD record)
{
    RECORD *p;
    int index;

    if (search(record.key) != NULL)
    {
        return -1;
    }

    p = (RECORD *)malloc(sizeof(RECORD));
    if (p == NULL)
    {
        perror("out of memory.\n");
        exit(1); // プログラムを強制終了
    }

    /*ハッシュ関数でrecord.keyのハッシュ値を求める*/
    index = hash(record.key);

    p->key = record.key;
    p->data = record.data;

    /* table[index]に新しく作成したレコードを挿入する*/
    p->next = table[index];
    table[index] = p;

    return 0;
}

int del(KEY key)
{
    RECORD *current, *previous;
    int index;

    index = hash(key);

    // ハッシュ値が指すバケット
    current = table[index];

    previous = NULL;

    // ハッシュ値のバケットから伸びてる連結リストが尽きるまで
    while (current != NULL)
    {
        if (keyequal(key, current->key))
        {
            if (previous == NULL)
            {
                // キーが先頭でみつかったらtable[index]が次のやつにうつす
                table[index] = current->next;
            }
            else
            {
                // キーが先頭以外でみつかったら一つ前にずらす
                previous->next = current->next;
            }

            free(current);
            return 0; // 削除成功
        }
        previous = current;
        current = current->next;
    }
    return -1; // 削除対象のキーが見つからない場合
}

int main(void)
{
    int command;
    KEY key;
    RECORD record;
    DATA *data;

    init();

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
                printf("挿入に成功しました。");
            }
            break;

        /*データを探索*/
        case 2:
            printf("探索したいキー値を入力してください：");
            scanf("%d", &key);
            data = search(key);

            if (data == NULL)
            {
                /* 探索失敗（一致するキーがなかった）時のエラーを表示*/
                printf("キー値 %d に対応するデータはありません", key);
            }
            else
            {
                /* 探索成功 => キー値、フィールドを出力する */
                printf("[キー値：%d] 名前 %s, 年齢 %d", key, data->name, data->age);
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
                printf("削除に成功しました。");
            }
            break;

        case 4:
            break;

        default:
            printf("コマンドが正しくありません");
            break;
        }
        printf("\n");

        // バッファに残ったゴミを初期化
        record.data.name[0] = '\0';
        record.data.age = -1;
    } while (command != 4);

    return 0;
}
