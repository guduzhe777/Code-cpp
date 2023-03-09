#include<bits/stdc++.h>

using namespace std;
//一块一块的处理
//二元组保存 时刻 编号
//以时刻排序  对 某时刻  同一订单数量 用cnt保存
//赋值到sorce 中
//再进行下一个  
//直到 时间t == T 不再判断
//对于上一次订单的时间进行保存  下一次订单的时候  进行 处理
//且更新 上一次订单时间为 这次订单//
//st保存是否处在优先级队列中
int n,m,T;//编号数量  m个订单  查询T时刻
//最多10^5个编号 10^5时刻
const int N = 10;
int sorce[10];//查看店家的分数
int st[N];//某个店家是否处在优先级中
int last[N];
typedef pair <int,int> PII;
PII order[N];//保存订单
int main()
{
    cin>>n>>m>>T;
    for(int i = 0;i<m;i++)
    {
        scanf("%d %d",&order[i].first,&order[i].second);
    }
    //输入完订单号
    sort(order,order+m);//订单号排序
    for(int i = 0;i<m;)//穷举方案数 
    {
        int cnt = 0,j = i;//得到 订单数量  看某个时刻 某个订单 的 结束地点
        int t = order[i].first;//对于 有订单的时刻  处理 t时刻之前的！！！
        int id = order[i].second;//保存这个编号 对这个编号 进行处理
        while(order[i] == order[j]&&j<m) j++;
        cnt = j - i;//保存 几个订单数量
        i = j;//对 结束点的地方 开始 订单遍历
        //t时刻 处理的并不是所有的  而是  你给我的 订单号之中的 商家进行更新
        //而处理订单之中没有的  需要 在后面集体进行处理

        // sorce[id] += cnt * 2;//编号的得分 为  +cnt  * 2 
        // if(sorce[id]>5) st[id] = true;

        
        sorce[id] -= t - last[id] - 1;          //这是t时刻之前的
        if(sorce[id]<0) sorce[id] = 0;//小于0 赋值0
        if(sorce[id]<=3) st[id] = false; 
        
        //细节：
        //减法 伴随  判断 小于0  小于等于3 
        //用 order[i] ==  order[j] j++ cnt = j - i 保存某时刻 某家店有几个订单然后操作
        //先处理 t时刻之前 将 未处理的先处理 减法 判断<0 <=3
        //为什么不拿先处理 之后呢？ 
        //先减法 有含0时候 不会减法  but  先加法  会把数字减去  
        //先减法  因为  我在处理的时候  他就是 0 然后 上一个处理时间为 0的时候  才符合逻辑！！！ 
       //更新last  与  sorce +2 是一起的 t时刻 进行加法 与 更新last 因为逻辑为 先 加法 然后才更新last！！！ 
        sorce[id] += cnt * 2;//编号的得分 为  +cnt  * 2 
        if(sorce[id]>5) st[id] = true;
        
        last[id] = t;   //处理时间更新  后续 需要用到   编号id商户最后一次处理时间 为t
    }
    //集体处理在这里
    for(int i = 1;i<=n;i++)
    {
        if(last[i]<T)  //如果最后一次订单时间小于T 那么 减法
        {
            sorce[i] -= T-last[i];
            if(sorce[i]<0) sorce[i] = 0;
            if(sorce[i]<=3) st[i] = false;
            
        }
    }
    int res = 0;
    for(int i = 1;i<=n;i++) //遍历某个物品 是否 在优先级中
    {
        res += st[i];
    }
    cout<<res<<endl;
    return 0;
}