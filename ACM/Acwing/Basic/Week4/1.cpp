

//以终为始
#include<bits/stdc++.h>

using namespace std;
int t;

int n;
int d,c;
int m;
bool justy(string s,int i)
{
    for(int j = i;j<s.length();j++)
    {
        if(s[j] == 'D') return false;
    }
    return true;
}
int main()
{
    cin>>t;
    for(int k = 1;k<=t;k++)
    {
        cin>>n>>d>>c>>m;
        static string s;
        cin>>s;
        int i;
        for(i = 0;i<s.length();i++)
        {
            if(s[i] == 'C')
            {
                if(c <= 0) break;
                c--;
            }else {
                if(d <= 0) break;//没有粮食
                d--,c += m;
            }
        }
        printf("Case #%d: %s\n",k,justy(s,i)?"YES":"NO");
    }

    return 0;
}