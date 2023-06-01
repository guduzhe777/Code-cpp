#include <bits/stdc++.h>

using namespace std;

map<char, int> mp; // mp [i] = j  i 字符 次数j

int main()
{

    int n = 9;
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= i; j++)
            printf("%d*%d=%d,", j, i, i * j);

    return 0;
}