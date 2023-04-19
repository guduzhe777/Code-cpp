//hash映射
//将 一串/一个东西 用其映射表示

//字符串不好处理 则 用映射标记 编号

//

#include<bits/stdc++.h>

using namespace std;
//不行，字符串无法建图。
//这是字符串 哈希映射为 数字的原因。

//当然可以直接string  string 通过 编号 找到   不行，字符串无法建图。

map<int,string> state;//被管理人员编号 - 管理编号 == 管理字符串 用哈希映射得到 编号 

map<string,int> relec1;//管理中心哈希 映射 编号
map<int,string> relec2;
map<int,vector<int> > admin;// 管理中心与被管理人员 
const int N = 2e5+10;
int n,m;

//检测是否出现过 出现过 不对其编号 不然对其编号
//string v[N];//string 类型没有查看数量
set<string> st; 
set<int> son[N];// son[i] = {c} i看管 c集合个病人

int fathers[N];//father[i] = k i的爸爸为k
int temp;
void dfs(int u)
{
    
    for(int v:son[u])
    {
        if(v<=n)
            ++temp;
        dfs(v);
    }
}
int main()
{
    cin>>n>>m;//老人数量 归属关系 
    int cnt = n;
    //通过编号建图
    while(m--)//归属关系
    {
        string s1,s2;
        int first,second;
        cin>>s1>>s2;
        if(isdigit(s1[0]))
        {
            first = stoi(s1);
        }else if(st.count(s1))
        {
            first = relec1[s1];//得到编号
        }else{
            //没有编号
            relec1[s1] = ++cnt;
            st.insert(s1);
            relec2[cnt] = s1;
            first = cnt;
        }
        if(st.count(s2))
        {
           second = relec1[s2];
        }else{
            st.insert(s2);//管理节点已经有 编号
            relec1[s2] = ++cnt;
            relec2[cnt] = s2;
            second = cnt;
        }
        fathers[first] = second;
        son[second].insert(first);
    }
    char op;
    while(cin>>op&& op != 'E')
    {
        if(op == 'Q')
        {
            string s3;
            cin>>s3;
            //查看 s3 管理人员
            int father = relec1[s3];
            temp = 0;
            dfs(father);
            printf("%d\n",temp);
            temp = 0;
        }else{//转移：
            string s1;
            int number;
            cin>>number>>s1;
            //number 入院或者转院
            int second = relec1[s1];
            if(fathers[number])//有上级
            {
                //转院
                int fat = fathers[number];
                son[fat].erase(number);
            }
            son[second].insert(number);
            fathers[number] = second;
        }
    }
    return 0;
}