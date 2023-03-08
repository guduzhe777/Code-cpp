//开始数码  随机选定  ID的开始数码是随机选定的。
//ID断号，另外一个ID重号。 
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
bool sn[N];
int rept,lack;//存储 缺少重复
int n;
int num;//存储输入的数字
int num_tem0,num_tem1;
int min0 = N,max0 = -N;
int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        while(cin>>num)
        {
            if(min0>num) min0 = num;
            if(max0<num) max0 = num;
            if(!sn[num])//如果没有值
            {
                sn[num] = true;//有了
            }
            else{
                rept = num;//重复的
            }
        }
    }
    for(int i = min0;i<= max0;i++)
    {
        if(!sn[i])//如果没有值
        {
            lack = i;
            break;
        }
    }
    cout<<lack<<" "<<rept;
    return 0;
}