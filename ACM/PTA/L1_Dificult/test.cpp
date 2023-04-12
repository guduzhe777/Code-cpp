#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a == 0 && b == 0 && c == 0)
    {
        printf("Zero Equation");
        return 0;
    }
    if (a == 0 && b == 0)
    {
        printf("Not An Equation");
        return 0;
    }
    double x = 0, x1 = 0, x2 = 0;
    x = b * b - 4 * a * c;
    if (a == 0)
    {
        printf("%.2f", -c / b);
        return 0;
    }

    if (x < 0)
    {
        x1 = sqrt(4 * a * c - b * b) / 2 / a;
        if (b == 0)
            b = -b; // b=0的时候要把符号变为正的；
        printf("%.2f+%.2fi\n", -b / 2 / a, x1);
        printf("%.2f-%.2fi\n", -b / 2 / a, x1);
    }
    else if (x == 0)
    {
        printf("%.2f", -b / 2 / a);
    }
    else if (x > 0)
    {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
        x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
        printf("%.2f\n%.2f", x1, x2);
    }
}
