#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str = "PTA";
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        string s;
        getline(cin,s);
        bool si = false;
        if(s[s.length() - 1] == '?')
        {
            si = true;//是问好
        }
        if(si)
        {
            int pos_str = s.find(str);
            if(pos_str != -1)
            {
                printf("Yes!\n");
            }else{
                printf("No.\n");
            }
        }else{
            printf("enen\n");
        }
    }
    return 0;
}