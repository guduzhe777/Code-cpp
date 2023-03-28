#include<bits/stdc++.h>

using namespace std;
const int N = 110;

int si1[10];
int si2[10];//分别判断原数组 后来数组含有的数字及数量
string s;//大数保存
int orig[N];
int change[N];
int main()
{
    cin>>s;
    for(int i = 0; i<s.length(); i++)
    {
        orig[i] = s[i] - '0';
        change[i] = orig[i]*2;//change[i] 原数字的double
    }
    for(size_t i = s.length()-1; i>0; i--)
    {
        if(change[i]>9)
        {
            change[i-1] += change[i]/10;
            change[i] %=10;

        }
    }//得到进位数字
    bool si = true;//默认输出Yes
    if(change[0]>9)
    {
        printf("No\n");
        si = false;
    }
    else
    {
        for(size_t i = 0; i<s.length(); i++) //遍历字符串中的每一位数字
        {
            si1[orig[i]]++;//原数组
            si2[change[i]]++;//double后的数组
        }
        for(int i = 0; i<10; i++)
        {
            if(si1[i] == si2[i]) continue;
            else
            {
                printf("No\n");
                si = false;
                break;
            }
        }
    }
    if(si)
    {
        printf("Yes\n");
    }
    for(int i = 0; i<s.length(); i++)
    {
        printf("%d",change[i]);
    }
    printf("\n");
}
