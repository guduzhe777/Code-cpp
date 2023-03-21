//一个笼子中有4种动物
//分别有2,4,6,8条腿
//当笼子有n条腿的时候
//输出 所以动物数量的可能
//若不可能则只输出-1

//n<=10^3(计算机1s只能计算 10^8次)
#include<bits/stdc++.h>

using namespace std;
struct other{
    int c,d;
    int s;
};
const int N = 10e7;
other others[N];
int n;
bool cmp_others(const other&o1,const other &o2)
{
    if(o1.s<o2.s) return true;
    if(o1.s == o2.s)
    {
        if(o1.c<o2.c) return true;
        if(o1.c == o2.c)
        {
            if(o1.d<o2.d) return true;
        }
        
    }
    return false;//有序排序 1 2  3  1 2  4 输出的时候有序输出
}
bool check(int mid,int target)
{
    if(others[mid].s>=target) return true;
    return false;//满足条件
}
int main()
{
    int si = false;//没找到合适的a b c d
    cin>>n;
    int i = 0;
    for(int c = 0;6 * c<=n;c++)
    {
        for(int d = 0;6 * c + 8 * d<=n;d++)
        {
            others[i].c = c;
            others[i].d = d;
            others[i].s = n - 6 * c - 8 * d;
        }
    }
    sort(others,others+i,cmp_others);
    for(int a = 0;2 * a<=n;a++)
    {
        for(int b = 0;2*a+4*b<=n;b++)
        {
            int l = -1,r = i;
            int sum = 2 * a+ 4 * b;
            while(l + 1 != r)
            {
                int mid = (r - l)/2+l;
                if(check(mid,sum)) r =  mid;
                else{
                    l = mid;
                }
            }
            if(sum == others[r].s)
            {
                cout<<a<<" "<<b<<" "<< others[r].c<<" "<<others[r].d<<endl;
                si = true;//找到了合适a  b c d
            }
        }
    }
    if(!si)
    {
        printf("-1\n");
    }
    return 0;
}