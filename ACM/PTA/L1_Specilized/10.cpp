#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
    while(cin>>n)
    {
        getchar();
        string s;
        int lowercase = 0;
        int capital = 0;
        int  space = 0;
        int  sign = 0;
        while(n--)
        {
            getline(cin,s);
            for(int i = 0;i<(int)s.length();i++)
            {
                if(s[i]<='Z'&&s[i]>='A')
                {
                    lowercase++;
                }else if('a'<=s[i]&&s[i]<='z')
                {
                    capital++;
                }else if(s[i] == ' ')
                {
                    space++;
                }else {
                    sign++;
                }
                
            }
        }
        printf("lowercase=%d capital=%d space=%d sign=%d\n",capital,lowercase,space,sign);

    }

    return 0;
}