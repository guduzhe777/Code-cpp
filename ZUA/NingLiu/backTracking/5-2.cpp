#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int minV = INT_MAX;
// void brackTracking(int floor,vector<bool> x,vector<vector<int>> c,int curV)
// {

//     if(floor > n)
//     {
//         minV = curV<minV?curV:minV;
//     }

//     for(int i = 1;i<=n;i++)
//     {
//         if(!x[i])
//         {
//             curV += c[floor][i];
//             x[i] = 1;
//             if(curV < minV) brackTracking(floor+1,x,c,curV);
//             curV -= c[floor][i];
//             x[i] = 0;
//         }
//     }

// }

void brackTracking(int floor,vector<int> x,vector<vector<int>> c,int curV)
{

    if(floor > n)
    {
        minV = curV<minV?curV:minV;
    }

    for(int i = floor;i<=n;i++)
    {
        swap(x[floor],x[i]);
        curV += c[floor][x[floor]];
        if(curV<minV) brackTracking(floor+1,x,c,curV);
        
        curV -= c[floor][x[floor]];
        swap(x[i],x[floor]);
    }

}

int main()
{
    cin>>n;
    vector<vector<int>> c(n+1,vector<int>(n+1,0));
    // vector<bool> x(n+1,0);
    vector<int> x;
    for(int i = 0;i<=n;i++)
    {
        x.push_back(i);
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    int curV = 0;
    brackTracking(1,x,c,curV);
    cout<<minV<<endl;
    return 0;
}