#include<bits/stdc++.h>

using namespace std;

int K,N;
const int Asize = 1e5 + 10;
int H[Asize],W[Asize];
bool check(int mid)
{
    //mid边长下 对于 N块 巧克力 可以分成 的数量 
    int res = 0;
    for(int i = 0;i<N;i++)
    {
        res += (H[i]/mid) * (W[i]/mid);
        if(res>=K) return true;//分出来大于K 返回可以
    }
    return false;//全部遍历完了还是无法达到K 返回fasle
}
int main()
{
    scanf("%d %d",&N,&K);
    for(int i = 0;i<N;i++)//N块
        scanf("%d %d",&H[i],&W[i]);
    int l = 0,r = 1e5 + 1;//二分多少块数
    while(l + 1 != r)
    {
        int mid = (r-l)/2 + l;
        if(check(mid)) l = mid;
        else r = mid;
    }
    //l 最后一个是 符合>=K情况下 的边长
    printf("%d",l);//输出最大边长
    return 0;
}