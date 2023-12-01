#include <bits/stdc++.h>

using namespace std;

const int N = 7;

int index[N][N];
int rent[N][N] =     {{0, 0, 0, 0, 0, 0, 0},

     {0, 0, 2, 3, 6, 8, 10},

     {0, 0, 0, 2, 5, 6, 8},

     {0, 0, 0, 0, 2, 3, 6},

     {0, 0, 0, 0, 0, 2, 4},

     {0, 0, 0, 0, 0, 0, 2},

     {0, 0, 0, 0, 0, 0, 0}};

// 预处理   默认最后一个断点情况 index[i][j] = j
//规模  首元素  尾元素 断点k
//j = i + r - 1 保证包含自己有r个元素
//k i+1 j-1
//k取值为 i+1 j-1之间  值默认已经是断点在j了



void boatCost(int n)
{
    for(int r = 3;r<=n;r++)
    {

        for(int i = 1;i<=n-r+1;i++)
        {
            int j = i + r-1;
            for(int k = i+1;k<j;k++)//直达情况为默认 [1][j] + [j][j] [1][1] + [1][j]
            {
                int cost = rent[i][k] + rent[k][j];
                if(cost<=rent[i][j])
                {
                    rent[i][j] = cost;
                    index[i][j] = k;
                }
            }
        }
    }
}
vector<int> v;
void print(int i, int j)
{
    if (j == index[i][j])
    {
        cout<<"换船站"<<j<<endl;
        return;
    }
    print(i, index[i][j]);
    print(index[i][j], j);
    // v.push_back(index[i][j]);
}

void print(int p[][N])
{
    cout<<"最优为数组为"<<endl;
    for(int i = 1;i<N;i++)
    {
        for(int j = i;j<N;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{

    int n;
    ios::sync_with_stdio(false);
    for(int i = 1;i<=6;i++)
        for(int j = 1;j<=6;j++)
        {
            index[i][j] = j;
        }
    // cin >> n;

    // if (n)
    // {
    //     for (int i = 1; i <= n; i++)
    //         for (int j = 1; j <= n; j++)
    //         {
    //             if (j > i)
    //             {
    //                 cout << i << "与" << j << "之间船费" << endl;
    //                 int x;
    //                 cin >> x;
    //                 rent[i][j] = x;
    //             }
    //         }
        
    // }

        boatCost(N-1);
        cout << rent[1][N-1] << endl;
        print(rent);
        print(1, N-1);
        // v.push_back(1);
        // for (int i = v.size() - 1; i >= 0; i--)
        // {
        //     cout << v[i] << "到";
        // }
        // cout << N-1 << endl;
    return 0;
}