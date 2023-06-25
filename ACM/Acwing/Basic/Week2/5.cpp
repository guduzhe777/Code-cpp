#include <bits/stdc++.h>

using namespace std;

// 结构体 里 可以放string
struct cloth
{
    string color;
    int d;
    int u;
};

int t;
int n;
bool cmp1(cloth &a,cloth &b)
{
    if(a.color == b.color)
    {
        return a.u<b.u;
    }
    return a.color<b.color;

}
bool cmp2(cloth &a, cloth &b)
{
    if(a.d == b.d)
    {
        return a.u<b.u;
    }
    return a.d<b.d;
}
int main()
{
    scanf("%d", &t);
    int tem = t;
    while (tem--)
    {
        vector<cloth> vc1,vc2;
        int cnt = 0;// cnt = j 有j个顺位相同
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            char s1[110];
            int d, u;
            scanf("%s", s1);
            scanf("%d %d", &d, &u);
            vc1.push_back({s1, d, u});
        }
        vc2 = vc1;
        sort(vc1.begin(),vc1.end(),cmp1 );
        sort(vc2.begin(),vc2.end(),cmp2 );
        for(int i = 0;i<n;i++)
        {
            if(vc1[i].u == vc2[i].u)
            {
                cnt++;
            }
        }
        printf("Case #%d: %d\n",t-tem,cnt);
    }

    return 0;
}