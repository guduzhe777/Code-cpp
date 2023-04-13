#include <bits/stdc++.h>

using namespace std;

queue<int> a, b;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int number;
        cin >> number;
        if (number % 2)
        {
            a.push(number);
        }
        else
        {
            b.push(number);
        }
    }
    bool fir = true;
    while (!a.empty() && !b.empty())
    {
        int cnt = 0;
        while (cnt < 2 && !a.empty())
        {
            cnt++;
            int c = a.front();
            a.pop();
            if (fir)
            {
                fir = false;
                printf("%d", c);
            }
            else
            {
                printf(" %d", c);
            }
        }
        cnt = 0;
        while (cnt<1&&!b.empty())
        {
            cnt++;
            int c = b.front();
            b.pop();
            if (fir)
            {
                fir = false;
                printf("%d", c);
            }
            else
            {
                printf(" %d", c);
            }
        }
    }
    int cnt = 0;
    while (!a.empty())
    {
        int c = a.front();
        a.pop();
        if (fir)
        {
            fir = false;
            printf("%d", c);
        }
        else
        {
            printf(" %d", c);
        }
    }
    while (!b.empty())
    {

        int c = b.front();
        b.pop();
        if (fir)
        {
            fir = false;
            printf("%d", c);
        }
        else
        {
            printf(" %d", c);
        }
    }
    return 0;
}