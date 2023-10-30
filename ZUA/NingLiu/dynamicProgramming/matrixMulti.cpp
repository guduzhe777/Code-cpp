#include<bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> Vii; 
Vii v1,v2;

int main()
{
    
    int rowa,cola,rowb,colb;
    ios::sync_with_stdio(false);
    cout<<"矩阵1 行 列  "<<endl;
    cin>>rowa>>cola;
    cout<<"矩阵1 值  "<<endl;
    for(int i = 0;i<rowa;i++)
    {
        vi  tem;
        for(int j = 0;j<cola;j++)
        {
            int x;
            cin>>x;
            tem.push_back(x);
        }
        v1.push_back(tem);
    }
    cout<<"矩阵2 行 列"<<endl;
    cin>>rowb>>colb;
    cout<<"矩阵2 值  "<<endl;
    for(int i = 0;i<rowb;i++)
    {
        vi  tem;
        for(int j = 0;j<colb;j++)
        {
            int x;
            cin>>x;
            tem.push_back(x);
        }
        v2.push_back(tem);
    }
    int c[5][6] = {0};
    for(int i = 0;i<rowa;i++)
    {
        for(int j = 0;j<colb;j++)
        {
            int sum = 0;
            for(int k = 0;k<cola;k++)
            {
                sum += v1[i][k] * v2[k][j];
            }
            c[i][j] = sum;
        }
    }
    for(int i = 0;i<rowa;i++)
    {
        for(int j = 0;j<colb;j++)
        {
            cout<<c[i][j]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}