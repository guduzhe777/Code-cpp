#include <iostream>

#include <fstream>

#include <iomanip>

using namespace std;

class Machineshop
{

    friend int Machine(int **, int **, int, int, int, int[]);

private:
    void Backtrack(int t);

    int **w; //各供应商的部件的重量

    int **c; //各供应商的部件的价格

    int *x; //当前设计方案

    int *bestx; //当前最优设计方案

    int cc; //当前价格

    int cw; //当前重量

    int bestw; //当前最小重量

    int n; //部件数

    int m; //供应商数

    int maxc; //价格最大预算
};

void Machineshop::Backtrack(int i)
{ 
    if(i>n) //第n个也需要选择
    {
        for(int i = 1;i<=n;i++)
        {
            bestx[i] = x[i]; // 第i个零件为x[i]
        }
        bestw = cw;
    }

    //最小机器质量设计
    for(int j = 1;j<=m;j++)
    {
        //第i个物品  选用 第j个人的
        x[i] = j;
        cc += c[i][j]; 
        cw += w[i][j];
        if(cc<=maxc&&cw<bestw)  //价格不大于maxc情况下 最小质量  到了倒数第二层 若满足当前价格小于最大预算 当前重量小于已知最小重量
                                // 则说明可以更新为目前的最好情况  条件作用于每一层
            Backtrack(i+1);
        cc -= c[i][j]; 
        cw -= w[i][j];
    }
}

int Machine(int **w, int **c, int n, int m, int maxc, int bestx[])
{

    Machineshop X; //初始化X

    X.x = new int[n + 1];

    X.m = m;

    X.n = n;

    X.c = c;

    X.w = w;

    X.maxc = maxc;

    X.cc = 0;

    X.cw = 0;

    X.bestx = bestx;

    X.bestw = 32767;

    for (int i = 1; i <= n; i++)

        X.x[i] = 0;

    X.Backtrack(1);

    return X.bestw;
}

int main()
{

    int **w, **c, *bestx, n, m, maxc, i, j, minw;

    ifstream inFile("input.txt");

    if (!inFile)

    {

        cerr << "Can not open file." << endl; // cerr 标准错误输出流

        exit(1);
    }

    inFile >> n >> m >> maxc;

    w = new int *[n + 1];

    for (i = 1; i <= n; i++)

        w[i] = new int[m + 1];

    for (i = 1; i <= n; i++)

        for (j = 1; j <= m; j++)
        {

            inFile >> w[i][j];
        }

    c = new int *[n + 1];

    for (i = 1; i <= n; i++)

        c[i] = new int[m + 1];

    for (i = 1; i <= n; i++)

        for (j = 1; j <= m; j++)
        {

            inFile >> c[i][j];
        }

    bestx = new int[n + 1];

    for (i = 1; i <= n; i++)

        bestx[i] = 0;

    minw = Machine(w, c, n, m, maxc, bestx);

    cout << "最佳设计方案:" << endl;

    for (i = 1; i <= n; i++)

        cout << "第" << i << "个零件选用第" << bestx[i] << "个销售商" << endl;

    cout << "最小重量:" << minw << endl;
}