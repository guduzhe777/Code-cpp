#include <iostream>

using namespace std;

int n = 3; //工作总数

int c[4][4] = //工作i分给工人j费用为cij

    {{0, 0, 0, 0},

     {0, 5, 3, 6},

     {0, 7, 7, 4},

     {0, 4, 5, 9}};

int x[4] = {0, 1, 2, 3}; //当前方案

int bestx[4] = {0}; //当前最优方案

int f = 0; //当前总费用

int bestf = 1000; //当前最优总费用

void Backtrack(int i)

{

    int j;

    if (i > n)

    {

        if (f < bestf)

        {

            for (j = 1; j <= n; j++)
                bestx[j] = x[j];

            bestf = f;
        }
    }

    else

    {

        for (j = i; j <= n; j++)

        {

            swap(x[i], x[j]);

            f += c[i][x[i]];

            Backtrack(i + 1);

            f -= c[i][x[i]];

            swap(x[i], x[j]);
        }
    }
}

int main()

{

    Backtrack(1);

    for (int i = 1; i <= n; i++)
        cout << bestx[i];

    cout << endl
         << bestf;

    return 0;
}