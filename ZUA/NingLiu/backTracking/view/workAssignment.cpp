#include <iostream>

using namespace std;



int n=3; //工作总数

int a[4][4]= //工作i分给工人j费用为a[i][j]

{{0,0,0,0},

{0,5,3,6},

{0,7,7,4},

{0,4,5,9}};



int x[4]={0,1,2,3}; //当前方案

int bestx[4]={0}; //当前最优方案

int f=0; //当前总费用 

int bestf=1000; //当前最优总费用



void Backtrack(int i)
{
    if(i>3)
    {
        if(bestf>f)
        {
            bestf = f;
            for(int j = 1;j<=3;j++)
            {
                bestx[j] = x[j];//保存最优路径
            }
            return;
        }
    }
    //工作i分给工人j费用为a[i][j]

    for(int j = i;j<=3;j++)
    {
        swap(x[i],x[j]);
        f += a[i][x[i]];
        Backtrack(i+1);
        swap(x[i],x[j]);
        f -= a[i][x[i]];
    }
}



int main()

{

    Backtrack(1);

    cout<<"最佳方案：";

    for(int i=1;i<=n;i++) cout<<bestx[i];

    cout<<endl<<"最低总费用：";

    cout<<bestf;

}

