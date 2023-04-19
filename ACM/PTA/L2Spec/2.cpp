#include<bits/stdc++.h>

using namespace std;


struct peo{
    double revu;//总的收入
    int cnt;//抢到红包数
    int id;//编号
};

double EPS = 0.001;
int n;
bool cmp(peo &a,peo &b)
{
    //如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出
    double sub = fabs(a.revu - b.revu);
    if(a.revu>b.revu&&sub>EPS) return true; //第一个是 绝对大于  第二个是 决定绝对大于
    else if(sub<EPS&&a.cnt>b.cnt) return true;
    else if(sub<EPS&&a.cnt==b.cnt&&a.id<b.id) return true;

    return false; 
 }
int main()
{
    cin>>n;
    vector<peo> v(n+1);
    for(int i = 1 ;i<=n;i++)
    {
        v[i].id = i;//编号为i
    }
    for(int i = 1;i<=n;i++)
    {
        int k,n;
        double p;
        cin>>k;
        for(int j = 0;j<k;j++)
        {
            cin>>n>>p;
            v[i].revu -= p/100;
            v[n].revu += p/100;
            v[n].cnt++;
        }
    }
    sort(v.begin()+1,v.end(),cmp);  //vector begin 永远为第一个  end永远为最后一个
    for(int i = 1;i<v.size();i++)
    {
        peo th = v[i];
        printf("%d %.2lf\n",th.id,th.revu);
    }
    return 0;
}