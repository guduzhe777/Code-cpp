#include <bits/stdc++.h>

using namespace std;

double avg;
int cntFall, cnt;
double grade;
int main()
{
    while (cin >> grade && grade >= 0)
    {
        if (grade < 60)
        {
            cntFall++;
        }
        avg += grade;
        cnt++;
    }
    if (cnt == 0)
    {
        printf("Average = %.2lf\n", cnt == 0 ? 0 : avg / cnt);
    }
    else
    {
        printf("Average = %.2lf\n", cnt == 0 ? 0 : avg / cnt);
        printf("Count = %d\n", cntFall);
    }

    return 0;
}