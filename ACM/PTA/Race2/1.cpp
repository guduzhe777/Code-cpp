//Djstl

//初始化边
//更新dis：最短距离 time：最短时间
//pre：最短距离  pree：最短时间
//初始化dis
//n-1次迭代
//更新最小，用最小接近每一个不在家庭中的点
//
#include<bits/stdc++.h>

using namespace std;
const int N = 510;
int dis[N],times[N];
struct pre{
	int pre0;//上一个点
	int cnt;//节点数 
};
struct pre_Time_dis{
	int pre0;
	int dis;
};
pre pre0[N];
pre_Time_dis pre0_time[N];
int d[N][N],ti[N][N];
bool si1[N],si2[N];//标记家庭 
int n,m;//点，边
int maxdis = 9999;
int maxtime = 9999;
//最短时间：初始化dis 更新 times，pre 
//n-1次迭代
//寻找非家庭最小，最小去接近 每一个点更新权值
 
void Djstl_time(int n,int u)
{
	for(int i = 0;i<n;i++)
	{
		times[i] = ti[u][i];
		if(times[i]<maxtime)
		{
			pre0_time[i].pre0 = u;
			pre0_time[i].dis = d[u][i];
		}else{
			pre0_time[i].pre0 = -1;
		}
		
	}
	si2[u] = 1;
	for(int i = 1;i<n;i++)
	{
		int best,temp = maxtime;
		for(int j = 0;j<n;j++)
		{
			if(!si2[j]&&times[j]<temp)
			{
				temp = times[j];
				best = j;//保存最小 
			}
		}
		si2[best] = true;
		for(int j = 0;j<n;j++)
		{
			if(!si2[j]&&ti[best][j]<maxtime)
			{
				int newtime = times[best] + ti[best][j];
				if(newtime<times[j])
				{
					times[j] = newtime;
					pre0_time[j].pre0 = best;
					pre0_time[j].dis = pre0_time[best].dis + d[best][j];
					
				}else if(newtime == times[j])
				{
					int newdis = pre0_time[best].dis + d[best][j];
					if(newdis<pre0_time[j].dis)
					{
						pre0_time[j].pre0 = best;
						pre0_time[j].dis = newdis;
						times[j] = newtime;
					}
				}
			 } 
		}
	}
}
void Djstl_dis(int n,int u)
{
	for(int i = 0;i<n;i++)
	{
		dis[i] = d[u][i];
		if(dis[i]<maxdis)//有边 
		{
			pre0[i].pre0 = u;
			pre0[i].cnt++;//节点数 
			
		}else{
			pre0[i].pre0 = -1;
		}
	}
	si1[u] = 1;
	for(int i = 1;i<n;i++)
	{
		int temp = maxdis,best;
		for(int j = 0;j<n;j++)
		{
			if(!si1[j]&&dis[j]<temp)//非家庭的最小 
			{
				temp = dis[j];
				best = j;
			}
		}
			si1[best] = 1;//最小找到 去接近
			for(int j = 0;j<n;j++)
			{
				if(!si1[j]&&d[best][j]<maxdis)
				{
					int newdis = dis[best] + d[best][j];
					if(newdis<dis[j])
					{
						pre0[j].pre0 = best;
						pre0[j].cnt++;
						dis[j] = newdis;
					}else if(newdis == dis[j]){
						if(pre0[best].cnt+1<pre0[j].cnt)
						{
							pre0[j].pre0 = best;//上一个点 
							pre0[j].cnt = pre0[best].cnt+1;//best到j点 多一个节点 
							dis[j] = newdis;//u到j距离更新 
						}
					}
				}
			 } 
		
	} 
}
//int dis[N],times[N];
//int pre[N],pre_time[N];
//int d[N][N],ti[N][N];
//bool si1[N],si2[N];//标记家庭 
vector<int> pa1,pa2;
void print_Path0(pre_Time_dis path[],int start0,int end0) //si0 = 0为time 
{

	
	pa1.push_back(end0);
	int temp = end0;
	while(temp != start0)
	{
		temp = pre0_time[temp].pre0;
		pa1.push_back(temp);
	}
	
	
}
void print_Path1(pre path[],int start0,int end0) //si0 = 0为time 
{

	
	pa2.push_back(end0);
	int temp = end0;
	while(temp != start0)
	{
		temp = pre0[temp].pre0;
		pa2.push_back(temp);
	}
	
}
void print_Vector(int end0)//比较vec相等，输出距离 时间 路程 
{
	
	if(pa1 == pa2)
	{
		printf("Time = %d; Distance = %d:",times[end0],dis[end0]);
		for(vector<int>::iterator it = pa1.end()-1;it != pa1.begin() - 1;it--)
		{
			if(it == pa1.end() - 1)
			{
				cout<<" "<<(*it);
			}else{
				cout<<" => "<<(*it);
			}
			
		}
	}else{
		printf("Time = %d:",times[end0]);
		for(vector<int>::iterator it = pa1.end()-1;it != pa1.begin() - 1;it--)
		{
			if(it == pa1.end() - 1)
			{
				cout<<" "<<(*it);
			}else{
				cout<<" => "<<(*it);
			}
			
		}
		cout<<endl;
		printf("Distance = %d:",dis[end0]);
		for(vector<int>::iterator it = pa2.end()-1;it != pa2.begin() - 1;it--)
		{
			if(it == pa2.end() - 1)
			{
				cout<<" "<<(*it);
			}else{
				cout<<" => "<<(*it);
			}
			
		}
	}
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
    	for(int j = 0;j<n;j++)
    	{
    		d[i][j] = d[j][i] = maxdis;
    		ti[i][j] = ti[j][i] = maxtime;
		}
	}//初始边 
    for(int i = 0;i<m;i++)
    {
        int v1,v2,one_way,length,time0;
        cin>>v1>>v2>>one_way>>length>>time0;
        if(one_way == 1)//单行线
        {
            d[v1][v2] = length;
            ti[v1][v2] = time0;
        }else{
            d[v1][v2] = d[v2][v1] = length;
            ti[v1][v2] = ti[v2][v1] = time0;
        }
    }
    int start0,end0;
    cin>>start0>>end0;
    Djstl_time(n,start0);//时间 
	
    print_Path0(pre0_time,start0,end0);//需要打印的数组，起始点 终点 
    
    Djstl_dis(n,start0);//点数 ，起点
	
    print_Path1(pre0,start0,end0);//需要打印的数组，起始点 终点 
	
	print_Vector(end0);
    return 0;
}
