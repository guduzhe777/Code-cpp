
//修正：将满足的符号放到数组中，一个个遍历 判断是否满足每一个连三
//不是判断次数 而是 满足则更改符号值
//
#include<bits/stdc++.h>

using namespace std;

char ans;
string a,b,c;//三行
string s = "XO+";

int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        ans = '?';//开始没有连三

        for(char x : s)
        {
            if(x == a[0] && x == a[1] && x == a[2])
                ans = x;//连三
            if(x == a[0] && x == b[0] && x == c[0])
                ans = x;//连三
            if(x == a[0] && x == b[1] && x == c[2])
                ans = x;//连三
            if(x == a[1] && x == b[1] && x == c[1])
                ans = x;//连三
            if(x == a[2] && x == b[1] && x == c[0])
                ans = x;//连三
            if(x == a[2] && x == b[2] && x == c[2])
                ans = x;//连三
            if(x == b[0] && x == b[1] && x == b[2])
                ans = x;//连三
            if(x == c[0] && x == c[1] && x == c[2])
                ans = x;//连三
        }
        if(ans == '?') cout<<"DRAW"<<endl;
        else cout<<ans<<endl;
    }


    return 0;
}