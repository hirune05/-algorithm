/*キュー１*/
#include <stdio.h>

#define N 10 // キューのサイズ

void enqueue(int[], int);
void dequeue(int[]);

int right = 0, left = 0;

int main(void)
{
    int Q[N];
    enqueue(Q, 4);
    enqueue(Q, 3);
    enqueue(Q, 8);
    dequeue(Q);
    dequeue(Q);
    enqueue(Q, 7);
    enqueue(Q, 1);
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
        printf("S[%d]=%d, right=%d, left=%d\n", left, Q[left], right, left);
        left += 1;
        if (left == N)
            left = 0;
    }
}