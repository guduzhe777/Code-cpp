//所以写个结构体 做题个数  罚时 然后是 自己的下标 三个一一比较。
//一个排序
//不过是由 做题次数 做题罚时 最后是下标
//先看能做多少题，把做多少题 对应罚时 都存储
//另外 做到这一题需要多少时间 t
//做完这道题 一共多少罚时 fine += t 
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
    if(a.cnt == b.cnt && a.solveTime == b.solveTime && a.index<b.index) return true;
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
            ll t = 0,fine = 0;
            int cnt = 0;
            for(int j = 0;j<m;j++)
            {
                if(t + sumTime[j] > h)
                    break;
                //t:到i-1需要时间
                cnt++;
                t += sumTime[j];
                //fine:到i-1罚时
                fine += t;
            }
            peo[i].cnt = cnt;
            peo[i].solveTime = fine;
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