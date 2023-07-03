
//将s 最小变化次数的变化成f含有的字母

//每一个字母转化都独立故：f = f1 + f2 +f3 ... 让f1 2 3各自最小即可
//即每个字母变成 f中字母最少需要多少。

//预处理，每一个字母变成f中字母最少需要多少次
//有个映射：f[i] - 'a' 把 a- z -> 0 - 25  //判断某个字符是否存在
//对于每一个字母映射到f中 需要多少次
//向左/向右： i + r  是向后 i - l 是向前 因为循环 所以 + N  % N 即循环 

#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10,M = 30;


int t;
char f[M];
char s[N];
bool si[M];//si[0] = 1 f中存在 'a'
int cnt[M]; // cnt[0] = 1 a变成b里面存在的 最少需要1次
int main()
{
    scanf("%d",&t);
    for(int cases = 1;cases<=t;cases++)
    {
        scanf("%s %s",s,f);
        memset(si,0,sizeof(si));//每个f不同 默认不存在
        for(int i = 0;f[i];i++)
        {
            si[f[i] - 'a'] = true;
        }
        for(int i = 0;i<26;i++)
        {
            int l = 0,r = 0;
            while(!si[(i + r) % 26] ) r++;
            while(!si[(i - l + 26)%26]) l++;
            cnt[i] = min(l,r);
        }
        //得到任意字母变成 b中任意字符最少需要 多少词
        int ans = 0;
        for(int i = 0;s[i];i++)
        {
            ans += cnt[s[i] - 'a'];
        }
        printf("Case #%d: %d\n",cases,ans);
    }

    return 0;
}
