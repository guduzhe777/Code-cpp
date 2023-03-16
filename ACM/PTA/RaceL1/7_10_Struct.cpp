#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
typedef struct time{
    int h,m,s;
}times; //不能和  结构体类型一样 /  或者不用再typedef 
times time0[N];
string s;
int i;//存储 时间到第几个
int n;
//转化时间标记  一天一共 24 * 60 * 60  86400s 从一个 未标记 到开始标记的前一个
//
int gettime(string s)
{
    sscanf(s.c_str(),"%d:%d:%d - %d:%d:%d",&time0[i].h,&time0[i].m,&time0[i].s);
    i++;
    
}

int main()
{
    cin>>n;
    
    while(n--)
    {
        getchar();
        getline(cin,s);
        
        gettime(s);
    }
    
    
    return 0;
}