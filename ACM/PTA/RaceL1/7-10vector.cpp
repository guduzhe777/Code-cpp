#include<bits/stdc++.h>
using namespace std;
const int N  = 100010; //有 86400 可能
typedef vector<int> vi;
typedef vecotr<vi> vii;
typedef vector<vii> viii;
viii time0;
string s;
int n;

//sscanf(str,格式);
//sscanf(time_str1.c_str(),"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
//~~~
int i;
void get_time(string s)//得到时分秒
{
    int h,int l,int s;
    sscanf(s.c_str(),"%d:%d:%d",&h,&m,&s);
    time0.push_back(h,m,s);
}
bool cmp_time(vii s1,vii s2)
{
    s1
}
int main()
{
    while(n--)
    {
        getline(cin,s);
        get_time(s);///得到时分秒
        sort(time0,time0+time0.size(),cmp_time);
    }
       
    return 0;
}