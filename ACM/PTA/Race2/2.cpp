//�ṹ��洢Ȩ��
//��һ�����ʱ�������·��
//�ڶ�����·���� ���ٽڵ�


#include<bits/stdc++.h.>

using namespace std;
const int N = 510;
int time[N][N];
int d[N][N];

struct ti_dis{
    int time,dis;
};
int pre_ti_dis[N];//pre_ti_dis[i] �������time  dis�� i ����һ����Ϊ
ti_dis ti_dis0[N];//ti_dis[i] ��i������ʱ�� ��̾���������ʱ�� ����
struct dis_cnt{
  int dis,cnt;  
};
dis_cnt dis_cnt0[N];//����������,�ڵ����
int pre_dis_cnt0[N];//������̾��� ���ٽڵ��Ȩ��  i����һ���ڵ�Ϊ
int n,m;
int maxdis = 9999;
int maxtime = 9999; //�ޱ߱�ʶ
//Djstl_time ��ʼ�� Ȩ �� n-1�ε���  �ҵ���С�Ǽ�ͥ  ȥ�ӽ��Ǽ�ͥ��Ա  �������ʺϵ�Ȩ
//int pre_ti_dis[N];//pre_ti_dis[i] �������time  dis�� i ����һ����Ϊ
//ti_dis ti_dis0[N];//ti_dis[i] ��i������ʱ�� ��̾���������ʱ�� ����
bool si1[N];//si1[i] = 1 i���ڼ�֮ͥ�� 
void Djstl_time(int n,int u)//����pre  ti_dis0
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
    cin>>n>>m;//���
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            d[i][j] = d[j][i] = maxdis;
            time[i][j] = time[j][i] = maxtime;
        }
    }//Ĭ���ޱ�
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
    int start0,end0;//��� �յ�
    cin>>start0>>end0;
    Djstl_time(n,start0);
    Djstl_dis(n,start0);
    return 0;
}

