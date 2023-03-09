#include<bits/stdc++.h>
using namespace std;
//基于绝对时间恒定  时差不过中间数字 可以消去
//将字符串转化 为 时间  且 转化为 秒  利于 加减法
//a在东  b在西  西到东 加时差（东边早经历 跑在西边前面）
//飞机经历时间 =  a.time - b.time - dh = b.time + dh （为a的时间） - a.time  
//17:48:19 21:57:24   a地 开始出发  a地时间  b地时间
//11:05:18 15:14:23   b地 开始出发  b地时间  a地时间
//绝对时间  b地 开始出发  b地时间化为a地时间 -   a地时间    b.time + dh （为a的时间） - a.time 
int n;
int get_second(int h,int m,int s)
{
    return h * 3600 + m * 60 + s;//返回秒数
}
int get_time()//得到 绝对时间的秒数
{
    int h1,m1,s1,h2,m2,s2,d;//保存 开始结束时间 是否 跨天  //d仅运算一次即可
    string time_str1;
    getline(cin,time_str1);//读入一行  对 一行的 开始结束时间 进行计算 
    if(time_str1.back() != ')') time_str1 += " (+0)";//如果 不含加0
    sscanf(time_str1.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
    return get_second(h2,m2,s2) - get_second(h1,m1,s1) + d * 24 * 3600;
    
}
int main()
{
    cin>>n;
    getchar();
    while(n--)
    {
        int second0 = (get_time() + get_time())/2;//去的时候 开始结束时间   回去的时候 开始结束时间 得到 2 * 飞行绝对时间
        int h0 = second0 / 3600,m0 = second0 % 3600 / 60,s0 = second0 % 60;
        printf("%02d:%02d:%02d\n",h0,m0,s0);
        
    }
    return 0;
}