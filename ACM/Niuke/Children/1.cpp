#include<bits/stdc++.h>


using namespace std;



map<char,int> mp;//mp [i] = j  i 字符 次数j

int n;
char si;
int main()
{

    scanf("%c",&si);
    scanf("%d",&n);
    //getchar();
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            // j*i=ans
            char s[110];
            sprintf(s,"%d*%d=%d,",j,i,j*i);
            string ss = s;
            for(char i : ss)
            {
                mp[i]++;
            }
        }
        
    }
    printf("%d\n",mp[si]);

    return 0;
}