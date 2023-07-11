//所以写个结构体 做题个数  罚时 然后是 自己的下标 三个一一比较。
#include<bits/stdc++.h>
#define  int long long
using namespace std;

typedef long long ll;

struct grade{
    int cnt;
    ll solveTime;
    int index;
};

int t;
int n,m,h;

const int INF = 1e9;
bool cmp(grade &a,grade &b)
{
    if(a.cnt>b.cnt) return true;
    if(a.cnt == b.cnt && a.solveTime<b.solveTime) return true;
    if(a.cnt == b.cnt && a.solveTime<b.solveTime && a.index<b.index) return true;
    return false;
}
signed main()
{

    cin>>t;
    while(t--)
    {
        cin>>n>>m>>h;
        vector<grade> peo(n);
        for(int i = 0;i<n;i++)
        {
            peo[i].index = i;
            
            vector<ll> sumTime;
            for(int j = 0;j<m;j++)
            {
                int x;
                cin>>x;
                sumTime.push_back(x);
            }
            sort(sumTime.begin(),sumTime.end(),less<ll>() );
            int cnt = 0;
            if(sumTime[0] < h) cnt++;
            for(int j = 1;j<m;j++)
            {
            
                sumTime[j] += sumTime[j-1];
                if(sumTime[j] <= h) cnt++;
            }
            for(int j = 0;j<m;j++)
            {
                if(j) sumTime[j] += sumTime[j-1];
            }
            int k;
            

            for(k = 0;k<m;k++)
            {
                if(sumTime[k]>h) break;
                
            }
            peo[i].cnt = cnt;
            peo[i].solveTime = k-1>=0?sumTime[k-1]:INF;
        }
        sort(peo.begin(),peo.end(),cmp);
        for(int k = 0;k<n;k++)
        {
            if(peo[k].index == 0) 
            {
                cout<<k + 1<<endl;
                break;
            }
        }
    }



    return 0;
}