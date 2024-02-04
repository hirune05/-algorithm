#include <stdio.h>
#include <stdlib.h>

#define P_BUCKET_SIZE 10 // ハッシュ表の大きさ
#define S_BUCKET_SIZE 10 // ハッシュ表の大きさ

typedef char KEY; // キーの型

/* データ部（キー以外）のフィールド */
typedef struct data
{
    int value;
} DATA;

/* データ一つを表すレコード */
typedef struct record
{
    KEY key;
    DATA data;
    struct record *next;
} RECORD;

/* グローバル変数 */
RECORD *p_table[P_BUCKET_SIZE];
RECORD *s_table[S_BUCKET_SIZE];

/*ハッシュ表の初期化*/
void init()
{
    int i;
    for (i = 0; i < P_BUCKET_SIZE; i++)
        p_table[i] = NULL;
    for (i = 0; i < S_BUCKET_SIZE; i++)
        s_table[i] = NULL;
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

DATA *search(RECORD **table, KEY key)
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

int add(RECORD **table, RECORD *record)
{
    RECORD *p;
    int index;

    if (search(table, record->key) != NULL)
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
    index = hash(record->key);

    p->key = record->key;
    p->data = record->data;

    /* table[index]に新しく作成したレコードを挿入する*/
    p->next = table[index];
    table[index] = p;

    return 0;
}

void p_createMap(RECORD **table, char P[], int length)
{
    printf("✅ p_createMap\n");
    int i = 0;

    for (i = 0; i < length; i++)
    {
        if (search(table, P[i]) == NULL)
        {
            DATA data;
            data.value = length - i - 1;

            RECORD record;
            record.key = P[i];
            record.data = data;
            add(table, &record);
        }
    }
}

void s_createMap(RECORD **table, char S[], int s_length, int p_length)
{
    int i = 0;
    printf("✅ s_createMap\n");
    for (i = 0; i < s_length; i++)
    {
        if (search(table, S[i]) == NULL)
        {
            DATA data;
            DATA *pData = search(p_table, S[i]);
            if (pData != NULL)
            {
                data.value = pData->value;
            }
            else
            {
                data.value = p_length;
            }
            RECORD record;
            record.key = S[i];
            record.data = data;
            add(table, &record);
        }
    }
}

int main()
{
    // テキスト
    char *T = "she sells sea shells on the sea shore";
    // パターン
    char *P = "shell";
    int n = 38; // テキストの文字数
    int m = 5;  // パターンの文字数

    int i = 0; // テキストに対して照合を行う位置の先頭
    int j = 0; // パターンに対して照合を行う位置
    int times = 0;

    init();

    p_createMap(p_table, P, m);

    for (int i = 0; i < P_BUCKET_SIZE; i++)
    {
        RECORD *p = p_table[i];
        while (p != NULL)
        {
            printf("Key: '%c', Value: %d\n", p->key, p->data.value);
            p = p->next;
        }
    }

    s_createMap(s_table, T, n, m);

    for (int i = 0; i < S_BUCKET_SIZE; i++)
    {
        RECORD *p = s_table[i];
        while (p != NULL)
        {
            printf("Key: '%c', Value: %d\n", p->key, p->data.value);
            p = p->next;
        }
    }

    i = 0;
    while (i < n - m + 1)
    {
        printf("%d", i);
        if (i < 10)
            printf("  ");
        else
            printf(" ");
        j = m - 1;
        while (T[i + j] == P[j] && j >= 0)
        {
            if (j - (m - 1) != 0)
                printf("   ");
            printf("%s\n", T);
            for (int k = 0; k < i + j + 3; k++)
                printf(" ");
            printf("+\n");
            for (int k = 0; k < i + 3; k++)
                printf(" ");
            printf("%s\n\n", P);
            j--;
            times++;
        }
        if (j == -1)
        {
            printf("テキスト index=%dの位置にパターン%sがありました\n", i, P);
            printf("比較回数は%dでした\n", times);
            return 0;
        }
        else
        {
            if (j - (m - 1) != 0)
                printf("   ");
            printf("%s\n", T);
            for (int k = 0; k < i + j + 3; k++)
                printf(" ");
            printf("|\n");
            for (int k = 0; k < i + 3; k++)
                printf(" ");
            printf("%s\n\n", P);
            i += search(s_table, T[i + (m - 1)])->value;
            times++;
        }
    }
    printf("❎ パターンが見つかりませんでした\n");
    printf("比較回数は%dでした\n", times);

    return 0;
}
