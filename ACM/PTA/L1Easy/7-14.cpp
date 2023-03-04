#include <bits/stdc++.h>

using namespace std;
long long a;
char Hex[20] = "0123456789ABCDEF";
int b[10100];
int main()
{
    cin >> a;
    int i;
    for (i = 1; a != 0; i++)
    {
        b[i] = a % 16;
        a /= 16;
    }
    for (int j = i - 1; j > 0; j--)
    {
        cout << Hex[b[j]];
    }
    return 0;
}