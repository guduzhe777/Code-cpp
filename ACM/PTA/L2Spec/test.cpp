#include<bits/stdc++.h>

string str;
int main()
{
    int i,j,n,m,k,t,l;
    
    getline(cin,str);
    l = s.length();
    for(i = l; i >= 2; i--)
    {
        for(j = 0; j + i < l; j++)
        {
            for(k = j, t = j + i; k <= t; k++, t--)
            {
                if(str[k] != str[t]) break;
            }
            if(k > t)break;
        }
        if(j + i < l) break;
    }
    if(i >= 2) printf("%d", i + 1);
    else printf("1");
    return 0;
}
