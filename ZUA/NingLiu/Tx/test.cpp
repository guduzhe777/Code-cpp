#include <stdio.h>
const int S = 100;
int main()
{
    int i, j, n, k = 0, total, num;
    int x[] = {15, 20, 35, 50, 65, 85, 100};
    int a[10];
    num = sizeof(x) / sizeof(x[0]);
    printf("请输入加满油后的行车距离：");
    scanf("%d", &n);
    total = n;
    j = 1;
    while (total < S)
    {
        for (i = k; i < num; i++)
        {
            if (x[i] > total)
            {
                a[j] = x[i - 1];
                j++;
                total = x[i - 1] + n;
                k = i;
                break;
            }
        }
    }
    for (i = 1; i < j; i++)
        printf("%d ", a[i]);
}