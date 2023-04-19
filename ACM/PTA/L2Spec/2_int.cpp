#include<bits/stdc++.h>

using namespace std;



struct peo{
    int revu,cnt,id;
};
int n;
bool cmp(peo &a, peo &b)
{
    if(a.revu>b.revu) return true;
    if(a.revu == b.revu&&a.cnt>b.cnt) return true;
    if(a.revu == b.revu&&a.cnt == b.cnt&&a.id<b.id) return true;

    return false;
}
int main()
{
    cin>>n;
    vector<peo> v(n+1);
    for(int i = 1;i<=n;i++)
    {
        v[i].id = i;
    }
    for(int i = 1;i<=n;i++)
    {
        int k,n,p;
        cin>>k;
        for(int j = 0;j<k;j++)
        {
            cin>>n>>p;
            v[i].revu -= p;
            v[n].revu += p;
            v[n].cnt++;
        }
    }
    sort(v.begin()+1,v.end(),cmp);
    for(int i = 1;i<=n;i++)
    {
        printf("%d %.2lf\n",v[i].id,1.0 * v[i].revu/100);
    }
    return 0;
}