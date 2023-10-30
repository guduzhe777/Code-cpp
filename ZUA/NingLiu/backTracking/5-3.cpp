#include<bits/stdc++.h>


using namespace std;


int n,m,d;
int minC = INT_MAX,minW = INT_MAX; //最小价格  最小重量

vector<int> chose;
void brackTracking(int r,int curC,int curW,vector<vector<int>> w,vector<vector<int>> c,vector<int> curChose)
{
    if(r > n)
    {
        if(curC < minC)
        {
            minC = curC;
            minW = curW;
            chose = curChose;
        }else if(curC == minC && curW<minW)
        {
            minW = curW;
            chose = curChose;
        }
        return;
    }
    //选择排列树/子集树 判断如何向前走
    //剪枝 + 回溯
    //剪枝根据条件
    //回溯切记将边的操作复原
    //一层一个部件 使用 哪一个商家 
    //
    for(int i = 1;i<=m;i++)  //商家
    {
        if(curC + c[r][i] > d||curW + w[r][i] > minW) 
        {
            return;
        }
        curC += c[r][i];
        curW += w[r][i];
        curChose.push_back(i);
        brackTracking(r+1,curC,curW,w,c,curChose);
        //选择回去 回溯 必须将这条边所做的操作复原！
        curC -= c[r][i];
        curW -= w[r][i];
        curChose.pop_back();
    }

}
int main()
{
    cin>>n>>m>>d;
    static vector<vector<int>> w(n+1,vector<int>(m+1));
    static vector<vector<int>> c(n+1,vector<int>(m+1));
    vector<int> curChose;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
        {
            cin>>c[i][j];
        }
        
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
        {
            cin>>w[i][j];
        }
        int curC = 0,curW = 0;

    brackTracking(1,curC,curW,w,c,curChose);
    cout<<"最小价格："<<minC<<endl;
    
    vector<int>::iterator it;
    int i = 1;
    for(it = chose.begin();it != chose.end();it++,i++)
    {
        cout<<i<<"部件来自："<<*it<<endl;
    }


    return 0;
}