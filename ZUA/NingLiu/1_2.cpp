#include<bits/stdc++.h>


using namespace std;


template<class T>
bool check(T a[],int s,int i)
{
    for(int j = s;j<i;j++)
    {
        if(a[j] == a[i]) return 0;
    }
    return 1;
}
template<class T>
void ranks(T a[],int s,int t)
{   
    if(s == t)
    {
        for(int i = 0;i<=3;i++)
        {
            std::cout<<a[i]<<" ";
        }
        std::cout<<"\n";
        return;
    }
    //不断换第一个元素 然后 进行下一个
    for(int i = s;i<=t;i++)
    {
        if(check(a,s,i))
        {
            swap(a[s],a[i]);
            ranks(a,s+1,t);
            swap(a[s],a[i]);
        }

    }
}
int main()
{




// 切记分治最关键是将复杂文件拆解为简单问题
// 一般+ 递归重复性做子问题 是递归+分治
// 如排列问题
    
    char a[4] = {'a','b','c','c'};
    ranks(a,0,3);

    return 0;
}