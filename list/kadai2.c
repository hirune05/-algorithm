/*スタック２*/
#include <stdio.h>

#define N 10

void push(int[], int);
void pop(int[]);
void clearStack(void);
int isEmpty(void);

int top = -1;

int main(void)
{
    int S[N];
    isEmpty();
    push(S, 4);
    isEmpty();
    push(S, 3);
    push(S, 8);
    pop(S);
    clearStack();
    isEmpty();
    push(S, 1);
    pop(S);
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
        printf("S[%d]=%d\n", top, S[top]);
        top -= 1;
    }
    else
        printf("アンダーフロー");
}

void clearStack(void)
{
    top = -1;
}

int isEmpty(void)
{
    if (top <= -1)
        return 0;
    else
        return 1;
}