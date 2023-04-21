
#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 1e5;
string s[N];
int main()
{
    cin >> n;
    getchar();
    //字符串 判断 对间隙时间 排序 输出；
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    sort(s, s + n);
    
    if (s[0].substr(0, 8) != "00:00:00" )
    {
        cout << "00:00:00" << " - "<<s[0].substr(0,8)<<"\n";            
    }
    for (int i = 0; i < n - 1; i++)
    {
        if(s[i].substr(11,8) != s[i+1].substr(0,8))
        {
            cout << s[i].substr(11,8)<< " - "<<s[i+1].substr(0,8)<<"\n";
        }
    }
    if(s[n-1].substr(11,8) != "23:59:59")
    {
        cout << s[n-1].substr(11,8)<< " - "<<"23:59:59"<<"\n";
    }
    return 0;
}