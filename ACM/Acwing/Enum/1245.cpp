#include<bits/stdc++.h>

using namespace std;
int n;
int num[4] = {2,0,1,9};
bool sign = false;//默认没有 2 0 1 9
int main()
{
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
        sign = false;//默认每个数字开始都没有 2 0 1 9
        int a = i;
        while(a)
        {
        
            for(int j = 0;j<4;j++)
            {
                if(a % 10 == num[j])//含有 2 0 1 9 求和 进行下一个
                {
                    sign = true;//有
                    break;//退出二层循环
                }
            }
            
            if(sign) //确实有 然后加 退出二层循环
            {

                sum += i;
                break;
            }
            a /= 10;//这一位不选 进行下一位
        }
        
    }
    cout<<sum;
    return 0;
}






