/*連結リスト*/
#include <stdio.h>
#include <stdlib.h>

/* リストのレコードを表す構造体テンプレートの宣言 */
typedef struct record
{
    int data;
    struct record *next;
} RECORD;

// リストの先頭を指し示すポインタ変数
RECORD *head = NULL;

void add(int x);
void del(void);
void print_all(void);

int main(void)
{
    int i;
    add(5);
    add(4);
    add(0);
    add(2);
    del();
    del();
    print_all();
    return 0;
}

void add(int x)
{
    // 新しいレコードを生成（動的確保）
    RECORD *p = (RECORD *)malloc(sizeof(RECORD) * 1);

    p->data = x;
    p->next = head;

    head = p;

    printf("add: %d \n", x);
}

void del(void)
{
    RECORD *p = head;
    // データが一つもない場合はリターン
    if (head == NULL)
    {
        printf("no node.\n");
        return;
    }
    // DEBUG出力用
    printf("dell: %d\n", p->data);

    head = p->next; // headを次のレコードに進める
    free(p);        // 退避させたレコードを解放
}

void print_all(void)
{
    RECORD *p = head;
    int i = 1;

    // データが一つもない場合はリターン
    if (head == NULL)
    {
        printf("no node.\n");
        return;
    }
    // DEBUG出力用
    printf("[head addr: %p]\n", head);

    // リストを操作しながら表示
    do
    {
        // 順に、先頭から何番目のデータか、データ値、レコードのアドレス次のレコードのアドレスが出力される
        printf("[pos: %3d, data: %5d, addr: %p, next: %p] \n", i, p->data, p, p->next);
        i++;
        p = p->next;
    } while (p != NULL);
}
