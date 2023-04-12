#include <bits/stdc++.h>

using namespace std;

double a, b, c, dt, x, y;
int main()
{

    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0)
    {
        printf("Zero Equation\n");
        return 0;
    }
    if (a == 0 && b == 0)
    {
        printf("Not An Equation\n");
        return 0;
    }
    if (a == 0)
    {
        printf("%.2lf\n", -c / b);
        return 0;
    }
    dt = b * b - 4 * a * c;
    if (dt > 0)
    {
        x = (-b + sqrt(dt)) / (2 * a);
        y = (-b - sqrt(dt)) / (2 * a);
        printf("%.2lf\n%.2lf", x, y);
    }
    else if (dt == 0)
    {
        x = (-b + sqrt(dt)) / (2 * a);
        printf("%.2lf\n", x);
    }
    else if (dt < 0)
    {
        x = -b / (2 * a);
        y = sqrt(-dt) / (2 * a);

        printf("%.2lf+%.2lfi\n", x == 0 ? 0:x, y);
        printf("%.2lf-%.2lfi\n", x == 0 ? 0:x, y);
    }

    return 0;
}