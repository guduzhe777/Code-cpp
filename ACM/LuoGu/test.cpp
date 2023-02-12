#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int w[105]={},f[105]={},ff[200010]={};
int main()
{
    int n,m=0;
    //freopen("smrtfun.in","r",stdin);
    //freopen("smrtfun.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%d%d",&w[i],&f[i]);//w数组存智商，f数组存情商（w变下标，f变值） 
      if(w[i]>0) m+=w[i];//计算背包容量（情商） 
    }
    m*=2;//m是平移的位数 
    memset(ff,-127/3,sizeof(ff)); 
    ff[m/2]=0;
    for(int i=1;i<=n;i++)
    {
        if(w[i]>0)//根据w[i]的符号确定循环方向，消除后效性,并从这里开始数组平移，防止出现负下标 
        for(int j=m;j>=w[i];j--)//接下来是01背包问题模板，保证每件物品只选一次 
          ff[j]=max(ff[j],ff[j-w[i]]+f[i]);
        else
        for(int j=0;j<=m-w[i];j++)//这个循环是数组平移弄出来的，由上个循环经数学运算得来。上个循环是m->w[i]，两边乘-1，变成-w[i]**<-**-m，再加m，即得到m-w[i]**<-**0 
          ff[j]=max(ff[j],ff[j-w[i]]+f[i]);
    }
    int ans=0,k=m/2;//k是平移的位数
    for(int i=0;i<=k;i++)
      if(ff[i+k]>=0 && i+ff[i+k]>ans)//ff[i+k]存的是情商，必须判断非负数，而从0开始的下标保证智商没负数 
        {
            ans=i+ff[i+k];
            //i是智商，
            ff[i+k];//是情商 
        }
    printf("%d",ans);
    //fclose(stdin);
   // fclose(stdout);
    return 0;
}