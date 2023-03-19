#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        printf("%d ", *it);
    }
    return 0;
}