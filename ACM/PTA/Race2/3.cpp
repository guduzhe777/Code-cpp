#include<bits/stdc++.h>

using namespace std;
//���ʱ�� �� ���·��
//���·���� ���ٽڵ�
const int N = 510;
int d[N][N];
int times[N][N];
struct dis_ti{//ȨΪʱ��  ·�� 
	int time,dis;
}; 
dis_ti dis0[N];
struct dis_dis{//ȨΪ ·��  �ڵ��� 
	int dis,cnt; 
};
dis_dis dis1[N];
int pre_Time[N];//���ʱ�� 
int pre_Dis[N];//���·�� ����һ�� 
int n,m; 
int max0 = 9999;//Ĭ���ޱ� 
bool si1[N];//si[i] = 1 i�����ڼ�ͥ 
void Djstl_time(int n,int u)
{
	for(int i = 0;i<n;i++)
	{
		dis0[i].time = times[u][i];
		if(dis0[i].time<max0)
		{
			pre_Time[i] = u;
			dis0[i].dis = d[u][i];//�б� 
		}else{
			pre_Time[i] = -1;
		}
	}
	si1[u] = 1;
	for(int i = 1;i<n;i++)//n - 1�ε��� 
	{
		int best,temp = max0;
		for(int j = 0;j<n;j++)
		{
			if(!si1[j]&&dis0[j].time<temp)
			{
				best = j;
				temp = dis0[j].time;
			}
		 } 
		 si1[best] = 1;
		 for(int j = 0;j<n;j++)//���·Ǽ�ͥ��j�� 
		 {
		 	int newtime = dis0[best].time + times[best][j];
		 	if(!si1[j]&&newtime<dis0[j].time)
		 	{
		 		pre_Time[j] = best;
		 		dis0[j].time = newtime;
		 		dis0[j].dis = dis0[best].time + times[best][j];
			 }else if(newtime == dis0[j].time)
			 {
			 	int newdis = dis0[best].dis + d[best][j];
				 if(newdis<dis0[j].dis)
				 {
				 	pre_Time[j] = best;
				 	dis0[j].time = newtime;
				 	dis0[j].dis = newdis;
				  } 
			 }
		 }
	}
}
bool si2[N];
void Djstl_dis(int n,int u)
{
	for(int i = 0;i<n;i++)
	{
		dis1[i].dis = d[u][i];
		if(dis1[i].dis<max0)
		{
			pre_Dis[i] = u;
			dis1[i].cnt++;
		}else{
			pre_Dis[i] = -1;
		}
	}
	si2[u] = 1;
	for(int i = 1;i<n;i++)
	{
		int best,temp = max0;
		for(int j = 0;j<n;j++)//�ҳ��Ǽ�ͥ ��j�� ���������̾����Ǹ���  
		{
			if(!si2[j]&&temp<dis1[j].dis)
			{
				temp = dis1[j].dis;
				best = j;
			}
		}
		si2[best] = 1;
		for(int j = 0;j<n;j++)
		{
			int newdis = dis1[best].dis + d[best][j];
			if(!si2[j]&&newdis<dis1[j].dis)//����j�ʺϵ�Ȩ 
			{
				pre_Dis[j] = best;
				dis1[j].dis = newdis;
				dis1[j].cnt++;
			 } else if(!si2[j]&&newdis == dis1[j].dis)
			 {
			 	if(dis1[best].cnt + 1<dis1[j].cnt)
			 	{
			 		pre_Dis[j] = best;
			 		dis1[j].cnt = dis1[best].cnt + 1;
			 		dis1[j].dis = newdis;
				 }
			 }
		}
	}
}
vector<int> pa0,pa1;
void sava_Path(int pre[],int st0,int end0)
{
	int temp = end0;
	pa0.push_back(temp);
	while(temp != st0)
	{
		
		temp = pre[temp];
		pa0.push_back(temp);
	}
	
	
}
print_Path(int pre0[],int pre1[],int end0)
{
	if(pa0 == pa1)
	{
		printf("Time = %d; Distance = %d: ",dis0[end0].time,dis1[end0].dis);
		for(vector<int>::iterator it = pa0.end() - 1;it != pa0.begin();it--)
		{
			if(it == pa0.end() - 1)
			{
				cout<<(*it);
			}else{
				cout<<" => "<<(*it);
			}
		}
	}else{
		printf("Time = %d: ",dis0[end0].time);
		for(vector<int>::iterator it = pa0.end() - 1;it != pa0.begin()-1;it--)
		{
			if(it == pa0.end() - 1)
			{
				cout<<(*it);
			}else{
				cout<<" => "<<(*it);
			}
		}
		cout<<endl;
		printf("Distance = %d: ",dis1[end0].dis);
		for(vector<int>::iterator it = pa1.end() - 1;it != pa1.begin()-1;it--)
		{
			if(it == pa1.end() - 1)
			{
				cout<<(*it);
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
			d[j][i] = d[i][j] = max0;
			times[i][j] = times[j][i] = max0;
		}
	}
	for(int i = 0;i<m;i++)
	{
		int v1,v2,oneway,length,time1;
		cin>>v1>>v2>>oneway>>length>>time1;
		d[v1][v2] = length;
		times[v1][v2] = time1;
		if(oneway)
		{
			d[v2][v1] = d[v1][v2];
			times[v2][v1] = times[v1][v2];
		}
	}
	int st0,end0;
	cin>>st0>>end0;
	Djstl_time(n,end0);
	Djstl_dis(n,end0);
	sava_Path(pre_Time,st0,end0);
	sava_Path(pre_Dis,st0,end0);
	print_Path(pre_Time,pre_Dis,end0);
	return 0;
 } 
