/*キュー２*/
#include <stdio.h>

#define N 10 // キューのサイズ

void enqueue(int[], int);
void dequeue(int[]);
void clearQueue(void);
int isEmpty(void);

int right = 0, left = 0;

int main(void)
{
    int Q[N];
    isEmpty();
    enqueue(Q, 3);
    enqueue(Q, 2);
    dequeue(Q);
    enqueue(Q, 5);
    dequeue(Q);
    clearQueue();
    enqueue(Q, 2);
    dequeue(Q);
    return 0;
}

void enqueue(int Q[], int x)
{
    Q[right] = x;
    right += 1;

    if (right == N)
        right = 0;
    if (left == right)
        printf("オーバーフロー");
}

void dequeue(int Q[])
{
    if (left == right)
        printf("アンダーフロー");
    else
    {
        printf("S[%d]=%d\n", left, Q[left]);
        left += 1;
        if (left == N)
            left = 0;
    }
}

void clearQueue()
{
    left = 0;
    right = 0;
}

int isEmpty(void)
{
    if (left == right)
        return 0;
    else
        return 1;
}