#include <iostream>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#define z 7 //数组z行z列，站点个数=z-1

using namespace std;

int r[z][z] =

    /*实例1          //z=6，5个站, 注意在开始处更改z的值

    {{0,0,0,0,0,0},

    {0,0,5,8,10,20},

    {0,0,0,4,8,12},

    {0,0,0,0,3,6},

    {0,0,0,0,0,2},

    {0,0,0,0,0,0}};  */

    /*实例2     */ // z=7，6个站, 注意在开始处更改z的值

    {{0, 0, 0, 0, 0, 0, 0},

     {0, 0, 2, 3, 6, 8, 10},

     {0, 0, 0, 2, 5, 6, 8},

     {0, 0, 0, 0, 2, 3, 6},

     {0, 0, 0, 0, 0, 2, 4},

     {0, 0, 0, 0, 0, 0, 2},

     {0, 0, 0, 0, 0, 0, 0}};

void Traceback(int i, int j, int **s)

{

    if (j == s[i][j]) //边界条件：在j站换船，即这是一段中间无换船的原子路程，不再递归；同时输出这段原子路程的终点站点

    {

        cout << "换船站" << j << endl;

        return;
    }

    Traceback(i, s[i][j], s);

    Traceback(s[i][j], j, s);
}

void MatrixChain(int n, int **m, int **s)

{

    for (int i = 1; i < z; i++)

        for (int j = 1; j < z; j++)

            m[i][j] = r[i][j]; //初始化m数组，m[i][j]的初始值为租金r[i][j]，表示从i到j直达不换船

    for (int i = 1; i < z; i++)

        for (int j = 1; j < z; j++)

            s[i][j] = j; //初始化s数组，初始值为j表示最后一次在j换船，也就是从i到j直达不换船

    for (int r = 3; r <= n; r++) // r=2（两个站）时，m[i][i+1]的最优值就是初始值r[i][i+1]，无需参与计算

        for (int i = 1; i <= n - r + 1; i++)

        {

            int j = i + r - 1;

            for (int k = i + 1; k < j; k++) //换船位置从i+1到j-1（位置j已经在赋初值时用过了，直达的情况已考虑过，现在考虑中间要换船的各种情况）

            {

                int t = m[i][k] + m[k][j];

                if (t < m[i][j])

                {

                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
}

void Print(int **m, int r, int c)

{

    for (int i = 1; i <= r; i++)

    {

        for (int j = 1; j <= c; j++)

        {

            if (i > j)

                cout << "\t"; // 横向跳到下一制表位置

            else

                cout << m[i][j] << "\t";
        }

        cout << endl
             << endl;
    }
}

int main()

{

    int **m = new int *[z];

    for (int i = 1; i < z; i++)

        m[i] = new int[z];

    int **s = new int *[z];

    for (int j = 1; j < z; j++)

        s[j] = new int[z];

    MatrixChain(z - 1, m, s); //求最优值

    cout << "最优值矩阵m：" << endl;

    Print(m, z - 1, z - 1); //显示二维数组m

    cout << "最优解矩阵s：" << endl;

    Print(s, z - 1, z - 1); //显示二维数组s

    cout << "最优值：m[1][" << z - 1 << "]=" << m[1][z - 1] << endl
         << endl;

    cout << "最优换船位置：";

    Traceback(1, z - 1, s); //求最优解

    cout << endl;

    return 0;
}