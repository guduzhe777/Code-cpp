#include <bits/stdc++.h>

using namespace std;

const int N = 6;
int rent[N][N] = {{0,0,0,0,0,0},

{0,0,5,8,10,20},

{0,0,0,4,8,12},

{0,0,0,0,3,6},

{0,0,0,0,0,2},

{0,0,0,0,0,0}}; 

int index[N][N];
void boatCost(int n)
{
    int r; //规模

    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++) //确定范围
        {
            int j = i + r - 1; //尾部

            for (int k = i; k < j; k++)
            {
                int v = rent[i][k] + rent[k][j];
                if (v < rent[i][j])
                {
                    rent[i][j] = v;
                    index[i][j] = k;
                }
            }
        }
    }
}
vector<int> v;
void print(int i, int j)
{
    if (i == j || !index[i][j])
        return;
    print(i, index[i][j]);
    print(index[i][j], j);
    v.push_back(index[i][j]);
}

int main()
{

    int n;
    ios::sync_with_stdio(false);
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
        print(1, N-1);
        v.push_back(1);
        for (int i = v.size() - 1; i >= 0; i--)
        {
            cout << v[i] << "到";
        }
        cout << N-1 << endl;
    return 0;
}