

//曼哈顿距离具有独立性：即 拐弯不影响最短距离

#include<bits/stdc++.h>

using namespace std;

int t;
int ax,ay,bx,by,cx,cy;

int  d(int x1,int y1,int x2,int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
//曼哈顿最短距离计算:最短距离不会根据中转点 改变 而改变  因为：总是满足折线
//将d(x,b) + d(x,c) = d(b,c)取代
int main()
{

    cin>>t;
    while(t--)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        int ans = (d(ax,ay,bx,by) + d(ax,ay,cx,cy) -d(bx,by,cx,cy)) / 2 + 1;
        cout<<ans<<"\n";
    }

    return 0;
}