#include<bits/stdc++.h>

using namespace std;
int m,n,w;
//距离不依靠
int obs(int x)
{
    x>0?x:-x;
}
int main()
{
    cin>>w>>m>>n;
    m--,n--;//在新数组中距离
    int r1 = n / w;
    int r2 = m / w;
    int c1 = n % w;
    int c2 = m % w;
    //奇数  行 逆序情况  坐标求法
    if(r1%2) c1 = w -  c1 - 1;
    
    if(r2 % 2) c2 = w - c2 - 1;
    cout<<obs(r1- r2) + obs(c1- c2)<<endl;
    return 0;
}