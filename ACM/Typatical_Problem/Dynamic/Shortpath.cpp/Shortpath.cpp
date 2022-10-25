#include<iostream>
#include<vector>
using namespace std;




// 二维vector保存:一个模板 模板里面是 类型 vector<int>
//vector< T > edge(n,   这里存的是 T的类型的元素 )
//vector<int>edege (n,8 整数类 ) vector<vector<int>>edge(n,vector<int>类型 ) vector<int>(n,<>之中存的类型0)
int main()
{
    //输入 图的 边  点 个数 某两个点之间的 权重用二维数组/ 二维vector保存
    cout<<"输入 点 边个数"<<endl;
    int  vex,Edge;
    vector<int>cost;//保存最短长度
    vector<int>path;//保存最短的下一个
    vector<vector<int>>edge(vex,vector<int>(vex,0));
    cin >> vex>>Edge;
    for(int i= 0;i<Edge;i++)
    {
        int m,n,len;//记录m n两点长度
        cin>>m>>n>>len;
        edge[m][n] = len;//保存长度        
    }
    //双循环遍历边长度  存在长度 比较
    for(int i = 0;i<Edge;i++)
    {
        for(int j = 0;j<Edge;j++)
        {
            if(edge[i][j])
            {
                
            }
        }
    }

    return 0;
}