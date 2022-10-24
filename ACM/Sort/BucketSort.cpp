#include<iostream>


using namespace std;

//把值出现次数存到桶里（数组里）
//桶排序 计数排序
//创建数组 [下标]++  访问计数数组  用数组值输出下标 

//如果是很大的一群数字呢？ 下标无法应用 怎么办呢 模让他变小？默德之可能相等  
int main(){

    int a[101],n;
    cin >>n;
    for(int i = 0;i<n;i++)
    {
        cin >>a[i];
    }
    int b[101] = {0};
    for(int i =0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(int i =0;i<=9;i++)
    {
        while(b[i]--)
        {
            cout << i<<endl;
        }
    }
    return 0;    
}