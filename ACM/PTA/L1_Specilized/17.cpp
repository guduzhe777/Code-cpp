#include <bits/stdc++.h>

using namespace std;

string s;
long long sum = 0;
int si = 1;
int main()
{

    while (cin >> s)
    {
        int i = 0;
        sum = 0;
        si = 1;
        if (!isalnum(s[0]))
        {
            si = -si;
            i = 1;
        }

        for (; i < s.length(); i++)
        {
            if ('A' <= s[i] && s[i] <= 'F')
            {
                sum = sum * 16 + s[i] - 'A' + 10;
            }
            else
            {
                sum = sum * 16 + s[i] - '0';
            }
        }
        printf("%lld\n", si * sum);
    }
    return 0;
}