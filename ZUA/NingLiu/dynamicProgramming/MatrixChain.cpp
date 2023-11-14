#include<bits/stdc++.h>


using namespace std;



struct matrixMessage{
    int row;
    int col;
};
vector<matrixMessage> vmatrix;
void matrixChain(vector<int> &p,int n, vector<vector<int>> &value,vector<vector<int>> &index)
{
    for(int r = 2;r<=n;r++)
    {
        for(int i = 1;i<=n - r + 1;i++)  //开始点范围确定
        {
            int j = i + r - 1;//结束点确定
            value[i][j] = value[i][i] + value[i+1][j] + p[i-1]*p[i]*p[j];
            index[i][j] = i;
            for(int k = i + 1;k<j;k++)
            {   //前行 后列 中间列1
            // p[i]: 第i个矩阵的列  i-1矩阵的行
                // int v = value[i][k] + value[k+1][j] + p[i]* p[k] * p[j];
                int v = value[i][k] + value[k+1][j] + p[i-1]* p[k] * p[j];
                if(v<value[i][j])
                {
                    value[i][j] = v;
                    index[i][j] = k;//确定最小分割点
                }
            }

        }
    }
}
void traceBack(int i,int j,vector<vector<int>> &index)
{
    if(i == j) return;
    traceBack(i,index[i][j],index);
    traceBack(index[i][j]+1,j,index);
    cout<<"Multiplu A "<<i<<", "<<index[i][j];
    cout<<" and A "<<(index[i][j]+1)<<", "<<j<<endl; 
    
}
// void print(int i,int j,vector<vector<int>> &index)
// {
//     if(i == j) return;
//     print(i,index[i][j],index); //出循环说明这一层已经分完了
//     print(index[i][j] + 1,j,index);//出循环说明这一层已经分完了
//     printf("(%d,%d)(%d,%d) ",i,index[i][j],index[i][j]+1,j);//最后应该是i = j 2 2第一个递归 3 3 第二个递归输出 两边分的东西 
//                                                             //返回 说明 2 3分完了1 2 3 再分 为 1 1  2 3 
//                                                             //递归只看重复的作用是什么千万别带入！！！
// }
int main()
{
    cout<<"请输入矩阵数量"<<endl;
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    // vmatrix.resize(vmatrix.size() + n + 1);

    vector<int> p(n + 1);
    vector<vector<int>> value(n + 1,vector<int>(n + 1));

    vector<vector<int>> index(n + 1,vector<int>(n + 1));
    
    cout<<"请输入矩阵行 列"<<endl;
    for(int i = 1;i<=n;i++)
    {
        cout<<i<<":";
        int col,row;
        cin>>row>>col;
        vmatrix.push_back({row,col});
        p[i-1] = row;
        if(i == n){
            p[i] = col;
        }
    }
    matrixChain(p,n,value,index);
    cout<<value[1][n]<<" "<<index[1][n];
    // print(1,n,index);
    traceBack(1,n,index);
    return 0;
}