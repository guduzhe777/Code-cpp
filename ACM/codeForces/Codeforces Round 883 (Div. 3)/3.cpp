#include<bits/stdc++.h>

using namespace std;

int t;
int n,m,h;

const int INF = 1e9;
//1.less<int>()
//思路很好 但是忘记了排序的条件：做题个数 然后 罚时！
//所以写个结构体 做题个数  罚时 然后是 自己的下标 三个一一比较。
int main()
{

    cin>>t;
    while(t--)
    {
        cin>>n>>m>>h;
        vector<vector<int>> solveTime(n);
        vector<int> sumTime;
        int standNum;
        int x;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                {
                    cin>>x;
                    solveTime[i].push_back(x);
                }
        for(int i = 0;i<n;i++)
        {
            sort(solveTime[i].begin(),solveTime[i].end(),less<int>() );
            
                for(int j = 0;j<m;j++)
                {
                    if(j)
                    {
                        solveTime[i][j] = solveTime[i][j-1] + solveTime[i][j];
                    }
                }
            int k;
            for(  k = 0;k<m;k++)
            {
                if(solveTime[i][k]>h) break;
            }
            
            sumTime.push_back(k-1>0?solveTime[i][k-1]:INF);
            if(!i)
            {
                standNum = k-1>0?solveTime[i][k-1]:INF;
            }
        }
        sort(sumTime.begin(),sumTime.end(),less<int>() );
        for(int s = 0;s<sumTime.size();s++)
        {
            if(standNum == sumTime[s])
            {
                cout<<s + 1<<endl;
                break;
            }
        }

    }


    return 0;
}