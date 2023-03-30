#include<bits/stdc++.h>

using namespace std;
int n;
const int N  = 1010;
char st[N][5];
struct xy{
    int x,y;
};
xy xy0;
int main()
{

    cin>>n;
    getchar();
    for(int i = 0;i<n;i++)
    {
        scanf("%s",st[i]);
        getchar();
        int pos = 0;
        for(int j = 0;j<5;j++)
        {
            int cnt = 0;
            while(st[i][j] == 'O'){
                 cnt++;
                 j++;
            }
            if(cnt == 2)
            {
                st[i][j-1] = '+';
                st[i][j] = '+';
                for(int k = 0;k<n;k++)
                {
                    printf("%s\n",st[k]);
                }
                return 0;
            }
            
        }
   
    }
    return 0;
}