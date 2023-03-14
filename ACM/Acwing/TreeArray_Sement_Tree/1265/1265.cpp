#include <iostream>
using namespace std;

const int N = 15010;
//空间换时间做法
//两个数组保存  二维信息
//二维可以保存三个维度值
//三个一维数组保存三个维度值
//but 访问信息 需要 n^2 复杂度
//三个一维 o(n)即可
int a[N],b[N],c[N];//两个一维数组 保存坐标 保存星级个数 范围为 N - 1   
int n;
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
    for(int i = 0;i<n;i++) //i指向数组 对应唯一确定嗲
    {
        int cnt = 0;//这个点星级为 0 
        for(int j = 0;j<i;j++)
        {
            if(a[j]<=a[i]) cnt++;
        }
        c[cnt]++;//某个星级数 ++
    }
    for(int i = 0;i<n;i++)
    {
        cout<<c[i]<<endl;
    }
    return 0;
}