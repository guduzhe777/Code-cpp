#include<bits/stdc++.h>
using namespace std;
int ans_p = 0,ans_q = 0;
/* 我想说  一直做同一件事情 用递归  条件需要限制！！！*/
bool dfs(int m,int p,int q)
{
    if(!m) return true;
    if(m>=p&&dfs(m - p,p,q)) {
        ans_p++;
        return true;
    }
    if(m>=q&&dfs(m - q,p,q)) {
        ans_q++;
        return true;
    }
    return false; 
}
int main()
{
    int p,q,m;
/* 尝试递归 求规律
while(1)
    {
        cin>>p>>q>>m;
        if(dfs(m,p,q))
        {
            printf("%d * %d + %d * %d = %d\n",ans_p,p,ans_q,q,m);
        }
        ans_p = 0,ans_q = 0;
    }
*/
    
  
    cin>>p>>q;
    int ans;
    for(int i = 1;i<=10000;i++)
    {
        if(!dfs(i,p,q)){
            ans = i;
        }
    }
    cout<<ans<<endl;
    //最大不能组成的数字：p * q - p - q;
/*printf("%d\n",p * q - p - q);*/
    
    return 0;
}