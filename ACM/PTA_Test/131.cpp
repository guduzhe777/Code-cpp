#include<iostream>
#include<vector>
using namespace std;
const int N = 510;
int g[N][N],sex[N],d[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) g[i][j]=0;
			else g[i][j]=1e9;
	
	for(int i=1;i<=n;i++)
	{
		char op;int k;scanf(" %c %d",&op,&k);
		if(op=='F') sex[i]=1;//女生 
		else sex[i]=2;//男生 
		for(int j=1;j<=k;j++)
		{
			int a,b;scanf("%d:%d",&a,&b);
			g[i][a]=b;
		} 
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
                
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(sex[i]!=sex[j])
				d[i]=max(d[i],g[j][i]);
	
	int d1=1e9,d2=1e9;//d1,表示女   d2,表示男 
	for(int i=1;i<=n;i++)
	{
		if(sex[i]==2) d1=min(d1,d[i]);//找男对女的最小距离 ,即男性的"大众情人" 
		else d2=min(d2,d[i]);//找女对男的最小距离 ,即女性的 "大众情人" 
	}
	
	vector<int> a,b;
	for(int i=1;i<=n;i++)//女性的"大众情人" 
	{
		if(sex[i]==2) continue;
		if(d[i]==d2) a.push_back(i);
	}	
	
	for(int i=1;i<=n;i++)//男性的"大众情人" 
	{
		if(sex[i]==1) continue;
		if(d[i]==d1) b.push_back(i);
	}
	 
	printf("%d",a[0]); 
	for(int i=1;i<(int)a.size();i++) 
		printf(" %d",a[i]);	
		
	puts("");
	
	printf("%d",b[0]); 
	for(int i=1;i<(int)b.size();i++)
		printf(" %d",b[i]);
	
	return 0;
}
