#include<bits/stdc++.h>

using namespace std;
const int N = 1010;
int main()
{
    int i = 0;
    char ch[N];
    while(cin>>ch[i])
    {
        
        
        if((ch[i]>='a')&&(ch[i]<='z'))
        {
            ch[i] -= 32;
        }
        else if((ch[i]>='A')&&(ch[i]<='Z'))
        {
            ch[i] += 32;
        }
        i++;
    }
    for(int j = 0;j<i;j++)
    {
        cout<<ch[j]<<endl;
    }
    return 0;
}