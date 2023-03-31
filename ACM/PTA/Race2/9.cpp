#include<bits/stdc++.h>


using namespace std;

//小顶堆 维护堆函数
// void heapify(int f[],int n,int i)//维护已有的 <=三个节点
// {
//     int large = i;
//     int lchild = 2 * i;
//     int rchild = 2 * i + 1;
//     //已有节点中 找寻最大 记录下标
//     //最大放到父节点  及 更新后续子节点
//     if(lchild<=n&&f[large]<f[lchild])
//     {
//         large = lchild;
//     }
//     if(rchild<=n&&f[large]<f[rchild])
//     {
//         large = rchild;
//     }
//     if(large != i)
//     {
//         swap(f[large],f[i]);
//         heapify(f,n,large);
//     }
// }
void heapify(int f[],int n,int i)//小顶堆维护
{
    int min0 = i;
    int lchild = 2 * i;
    int rchild = 2 * i + 1;
    if(lchild<=n&&f[min0]>f[lchild])
    {
        min0 = lchild;
    }
    if(rchild<=n&&f[min0]>f[rchild])
    {
        min0 = rchild;
    }
    if(min0 != i)
    {
        swap(f[min0],f[i]);
        heapify(f,n,min0);
    }
}
void heap_Sort(int f[],int n)
{
    for(int i = n/2;i>0;i--)
    {
        heapify(f,n,i);
    }//维护堆
}
const int N = 1010;
int f[N];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>f[i];
    }
    heap_Sort(f,n);
    //map 记录 数字 及下标
    for(int i = 1;i<=n;i++)
    {
        printf("%d ",f[i]);
    }
    map<int,int> mp;
    for(int i = 1;i<=n;i++)
    {
        mp[f[i]] = i;//值与下标对应
    }
    for(int i = 0;i<m;i++)
    {
        bool si = false;//默认说的是对的
        int a;
        string s;
        cin>>a;
        cin>>s;
        if(s == "is")
        {
            string s1,s2;
            cin>>s1;
            cin>>s2;
            if(s2 == "root")
            {
                if(mp[a] == 1)//根节点
                {
                    si = true;//改变
                }
            } else if(s2 == "parent")
            {
                string s3;
                int b;
                cin>>s3;
                cin>>b;
                if(mp[a] == mp[b]/2)
                {
                    si = true;
                }
            } else if(s2 == "child")
            {
                string s3;
                int b;
                cin>>s3;
                cin>>b;
                if(mp[a]/2 == mp[b])
                {
                    si = true;
                }
            }

        }else if(s == "and")
        {
            int y;
            cin>>y;
            if(mp[a]/2 == mp[y]/2)
            {
                si = true;
            }
            getline(cin,s);
        }
        if(si)
        {
            printf("T\n");
        }else{
            printf("F\n");
        }
        
    }
    return 0;
}