// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int N, M, K,sum = 0,cnt = 0;
//     scanf("%d %d %d", &N, &M,&K);
//     int A[100][100];
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             scanf("%d",&A[i][j]);
//         }
//     }

//     cout<<cnt<<endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
const int size = 510;
int arr[size][size] = {0};
int N, M, K;

int main()
{
    int x,ans = 0;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> x;
            arr[i][j] = x + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    // for(int i = 1;i<=N;i++)
    // {
    //     for(int j = 1;j<=M;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //以左上角为静止点  以x 为静止 横坐标

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int x = i; x <= M; x++)
            {
                for (int y = j; y <= N; y++)
                {
                    if(arr[y][x] - arr[j-1][x] - arr[y][i-1] + arr[j-1][i-1]<=K)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}