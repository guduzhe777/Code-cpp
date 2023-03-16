#include<bits/stdc++.h>

using namespace std;
//字符与次数 保存在 二元组
//对输入字符数量++
//输出
const int N = 1011;
int sign;
typedef pair <char,int> PII;
PII ans[N];
int main()
{
    string s;
    while(getline(cin,s))
    {
        memset(ans,0,sizeof(ans));
        for(int i = 0;i<s.length();i++)
        {
            if(('A'<=s[i])&&(s[i]<='Z')||('a'<=s[i])&&(s[i]<='z'))
            {
                ans[s[i]].first = s[i],ans[s[i]].second++;
                sign = s[i];//记录最后一个
            }
        }
        for(int i = 0,cnt = 0;i<N;i++)
        {
            if(ans[i].second)
            {
                
                if((cnt % 10) == 0)
                {
                    printf("%c--%d",ans[i].first,ans[i].second);
                }
                else{
                    printf(" %c--%d",ans[i].first,ans[i].second);
                }
                if((cnt + 1) % 10 == 0||sign == i)//最后一个
                {
                    printf("\n");
                }
                cnt++;//记录 第几个输出
            }
        }
    }
    
    return 0;
}