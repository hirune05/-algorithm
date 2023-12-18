/*スタック*/

#include <stdio.h>

#define N 10

void push(int[], int);
void pop(int[]);

int top = -1;

int main(void)
{
    int S[N];
    push(S, 4);
    push(S, 3);
    push(S, 8);
    pop(S);
    pop(S);
    push(S, 7);
    push(S, 1);
    pop(S);

    return 0;
}

void push(int S[], int x)
{
    if (top < (N - 1))
    {
        top += 1;
        S[top] = x;
    }
    else
        printf("オーバーフロー");
}

void pop(int S[])
{
    if (top >= 0)
    {
        printf("S[%d]=%d, top=%d\n", top, S[top], top);
        top -= 1;
    }
    else
        printf("アンダーフロー");
}