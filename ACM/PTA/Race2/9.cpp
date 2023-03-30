#include<bits/stdc++.h>

using namespace std;
const int N = 1010;
int f[N];
//维护头节点
void heapify(int f[],int n,int i)
{
    int large = i;
    int lchild = 2 * i;
    int rchild = 2 * i + 1;//父亲下标= 儿子下标除以2即可
    if(lchild<n&&f[large]<f[lchild]) 
    {
        large = lchild;
    }
    if(rchild<n&&f[large]<f[rchild])
    {
        large = rchild;
    }
    if(large != i)//最大不是父亲
    {
        swap(f[large],f[i]);
        heapify(f,n,large);//维护后续
    }
}
void heap_Sort(int f[],int n)
{
    //建堆/维护父节点们
    for(int i = n / 2;i>0;i--)
    {
        heapify(f,n,i);
    }
    
}
int m,n;
bool check(char ch)
{
    if(ch>='0'&&ch<='9')
    {
        return true;
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>f[i];
    }
    
    heap_Sort(f,n);
    while(m--)
    {
        string s;
        getline(cin,s);
        for(int i = 0;i<s.length();i++)
        {
            int sum1 = 0,sum2 = 0;
            while(check(s[i])) 
            {   
                i++;
                sum1 = sum1 * 10 + s[i] - '0'
            }
            sum2 = sum1;//对出现的数字进行保存
        }
    }

    return 0;
}