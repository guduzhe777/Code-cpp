#include<bits/stdc++.h>

using namespace std;
//根据对方的出招，给出对应的赢招

//隔 K 次输一次
//给出n个系统产生的k
//k1  k2  k3
//开始 k1次后输 第一次输了后 隔 k(1+1)k2 次再输  第 3次输  第k4次后 再输

struct st{
    string win,fail;
};
map<string,st> mp;
int a[12];
int n;
//则随机数按顺序循环使用。例如在样例中，系统产生了 3 个随机数 {2, 4, 1}，则你需要：赢 2 次，输 1 次；赢 4 次，输 1 次；赢 1 次，输 1 次；
int main()
{
    mp["ChuiZi"] = {"JianDao","Bu"}; //自己想赢/ 输
    mp["Bu"] = {"ChuiZi","JianDao"};
    mp["JianDao"] = {"Bu","ChuiZi"};

    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int pos = 0;//指向应该赢的次数
    int cnt = 1;//已经赢的次数
    while(1)
    {
        string s;
        cin>>s;
        if(s == "End")
        {
            break;//结束
        }
        if(cnt <= a[pos])
        {
            cout<<mp[s].fail<<"\n";
            cnt++;
        }else{//应该输
            cout<<mp[s].win<<"\n";
            cnt = 1;
            pos++;//更新应该赢的次数
            pos %= n;
        }
        
    }
    return 0;
}