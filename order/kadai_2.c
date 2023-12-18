/*最大値の計算*/

#include <stdio.h>

int main(void)
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 1 : 1
    int i, max;                                  // 1 : 1
    max = x[0];                                  // 1 : 1
    for (i = 0; i < 10; i++)                     // 1 : 11
    {
        if (max < x[i]) // 10 : 10
            max = x[i]; //  0 : 10
    }
    printf("最高値は%dです", max); // 1 : 1
    return (0);                    // 1 : 1
}