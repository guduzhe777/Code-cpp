

//7-3 智能护理中心统计
//https://pintia.cn/problem-sets/1648179596815867904/exam/problems/1648179672531480576


//我看出来是map  but 人会改变即移动
//只看人数 即可
//========= 
//对人数修改？ 
//人数如何转化
//=========
//四大难处
//：逻辑 分析 题目 转化
//：数据结构 STL
//：难以理解的 dp  
//：细节 

//字符串 哈希映射
//哈希映射  变成编号
//

//最后 老人 数量为 vector的大小
//
//
//数组存储 父亲 类似并查集
//
#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int st[N];
int n,q;
struct node{
    int cnt;
    int si;
};
map<string,node> mp;
bool valid(string s)
{
    for(int i = 0;i<s.length();i++)
    {
        if(('A'<=s[i])&&(s[i]<='Z'))
        {
            return true;//是字母
        }
    }
    return false;
}
int main()
{
    cin>>n>>q;
    while(q--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(valid(s1))//是字母
        {
            
        }
    }

    return 0;
}