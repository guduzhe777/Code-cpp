#include<bits/stdc++.h>

using namespace std;
string str;
int T;

int cnt = 0;
int main()
{
    cin>>T;
    
    while(T--)
    {
        cnt = 0;
        getchar();
        getline(cin,str);
        for(int i = 0;i<str.length();i++)
        {
            if((str[i]>='0')&&(str[i]<='9'))
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    
    return 0;
}