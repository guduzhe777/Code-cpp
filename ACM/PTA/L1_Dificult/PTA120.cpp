#include<bits/stdc++.h>

using namespace std;
char ch;
double ans;
int main()
{
    
    while((ch = getchar())!='\n')
    {
        ch>'Z'?ch = ch - 32:ch = ch;
        
        ans = ans * 26 + (ch - 'A'+1); 
    }
    printf("%.2lf\n",ans);
    return 0;
}
