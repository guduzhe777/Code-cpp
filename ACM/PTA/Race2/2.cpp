//结构体存储权；
//第一个最短时间下最短路径
//第二个：路径下 最少节点


#include<bits/stdc++.h.>

using namespace std;
const int N = 510;
int time[N][N];
int d[N][N];

struct ti_dis{
    int time,dis;
};
int pre_ti_dis[N];//pre_ti_dis[i] 符合最短time  dis下 i 的上一个点为
ti_dis ti_dis0[N];//ti_dis[i] 到i点的最短时间 最短距离条件：时间 距离
struct dis_cnt{
  int dis,cnt;  
};
dis_cnt dis_cnt0[N];//条件：距离,节点个数
int pre_dis_cnt0[N];//符合最短距离 最少节点的权下  i的上一个节点为
int n,m;
int maxdis = 9999;
int maxtime = 9999; //无边标识
//Djstl_time 初始化 权 拿 n-1次迭代  找到最小非家庭  去接近非家庭成员  更新最适合的权
//int pre_ti_dis[N];//pre_ti_dis[i] 符合最短time  dis下 i 的上一个点为
//ti_dis ti_dis0[N];//ti_dis[i] 到i点的最短时间 最短距离条件：时间 距离
bool si1[N];//si1[i] = 1 i点在家庭之中 
void Djstl_time(int n,int u)//更新pre  ti_dis0
{
    for(int i = 0;i<n;i++)
    {
    	ti_dis0[i].time = time[u][i];
        if(time[u][i]<maxtime)
        {
            pre_ti_dis = u;
            ti_dis0[i].dis = d[u][j];
            
        }else{
            pre_ti_dis = -1;
        }
    }
    si1[u] = 1;
    for(int i = 1;i<n;i++)
    {
    	int best,temp = maxtime;
    	for(int j = 0;j<n;j++)
    	{
    		if(pre_ti_dis[j].)
		}
	}
	
}
int main()
{
    cin>>n>>m;//点边
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            d[i][j] = d[j][i] = maxdis;
            time[i][j] = time[j][i] = maxtime;
        }
    }//默认无边
    for(int i = 0;i<m;i++)
    {
        int v1,v2,oneway,length,time;
        cin>>v1>>v2>>oneway>>length>>time;
        if(oneway)
        {
            d[v1][v2] = length;
            time[v1][v2] = time;
        }else{
            d[v1][v2] = d[v2][v1] = length;
            time[v1][v2] = time[v2][v1] = time;
        }
    }
    int start0,end0;//起点 终点
    cin>>start0>>end0;
    Djstl_time(n,start0);
    Djstl_dis(n,start0);
    return 0;
}

