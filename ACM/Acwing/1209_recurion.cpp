#include<bits/stdc++.h>

using namespace std;
//错误示范：
// int n;
// const int N = 7;
// int a_arr[N],b_arr[N],c_arr[N];
// int a,b,c;

//一个数组 分成三段！
//带入验证
int n;
const int N = 11;
int f[N];//序列存储
bool bool_arr[N];//看某个数字使用状态
int a,b,c;
int cnt = 0;//存储 所有 a b c 得 n的次数
int cacl(int l,int r)
{   
    int res = 0;
    for(int i = l;i<=r;i++)
    {
        // res += f[i] * pow(10,r-i);
        res = res * 10 + f[i];
    }
    return res;
}
void obs(int x)
{
    if(x>9)
    {
        for(int i = 1;i<=7;i++)//为序列切割
        {
            for(int j = i + 2;j<=9;j++)
            {
                a = cacl(1,i);
                b = cacl(i+1,j-1);
                c = cacl(j,9);
                //切割完毕
                
                if(n * c == a * c + b)
                {
                    cnt++;
                }
            }
        }
        
        return;
    }

    for(int i = 1;i<=9;i++)
    {
        if(bool_arr[i])
        {
            continue;
        }
        f[x] = i;
        bool_arr[i] = true;
        obs(x+1);
        bool_arr[i] = false;
    }

}
int main()
{
    scanf("%d",&n);
    obs(1);
    printf("%d",cnt);
    return 0;
}