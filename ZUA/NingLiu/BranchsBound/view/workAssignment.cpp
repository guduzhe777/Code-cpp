#include <iostream>

using namespace std;

template <typename T>

class minHeap //小顶堆

{

private:
    T d[1000]; //堆空间，最多容纳1000个元素

    int tail; //尾元素下标

    void dsort(int t) //堆排序

    {

        int L = t * 2 + 1, R = t * 2 + 2;

        if (L <= tail)

        {

            dsort(L);

            if (d[t].value() > d[L].value())
                swap(d[t], d[L]);
        }

        if (R <= tail)

        {

            dsort(R);

            if (d[t].value() > d[R].value())
                swap(d[t], d[R]);
        }
    }

public:
    minHeap() : tail(-1) {}

    void Add(T dat) //向尾部添加元素

    {

        d[++tail] = dat;

        dsort(0);
    }

    void Delete(T &e) //弹出队头元素，没有考虑队列已空的情况

    {

        e = d[0];

        swap(d[0], d[tail--]);

        dsort(0);
    }

    bool IsEmpty() //判空

    {

        return tail == -1;
    }
};

int n = 3; //工作总数

int c[4][4] = //工作i分给人j费用为cij

    {{0, 0, 0, 0},

     {0, 5, 3, 6},

     {0, 7, 7, 4},

     {0, 4, 5, 9}};

struct Qnode

{

    int x[4]; //节点对应的解向量

    int f; //节点当前费用

    int i; //节点所在层数

    int pot; //优先级指标，子树最小可能费用

    int value() { return pot; }
};

minHeap<Qnode> Q; //活结点最小堆

int minf[5] = {0}; //各工作最小费用

int maxf[5] = {0}; //各工作最大费用

int i = 1; //当前扩展结点所处的层

int x[4] = {0, 1, 2, 3}; //当前方案

int f = 0; //当前费用

int bestf = 1000; //当前最优费用

Qnode E; //当前扩展节点

void MaxLoading()

{

    int j, k, up, down;

    //先计算最小出边和，最大出边和

    for (j = 2; j <= n; j++) //各层最小最大出边，就是各工作的最大和最小费用

    {

        minf[j] = maxf[j] = c[j][1];

        for (k = 2; k <= n; k++)
        {

            if (c[j][k] < minf[j])
                minf[j] = c[j][k];

            if (c[j][k] > maxf[j])
                maxf[j] = c[j][k];
        }
    }

    for (j = n - 1; j >= 2; j--) //直接累加各层剩余未安排工作的最小最大出边和

    {

        minf[j] += minf[j + 1];

        maxf[j] += maxf[j + 1];
    }

    //优先队列搜索

    while (i != n + 1) //第一个叶节点出队即可停止，退出后f即为最优值，x即为最优解

    {

        for (j = i; j <= n; j++) //遍历下级节点

        {

            swap(x[i], x[j]);

            up = down = f + c[i][x[i]];

            up += minf[i + 1]; //最大潜力

            down += maxf[i + 1]; //最差情况，至少可实现的解，最优解下限

            if (down < bestf)
                bestf = down; //最大可能费用比bestf小，bestf就可以更新了

            if (up <= bestf) //最小可能费用小于等于bestf，这个节点子树还有希望应继续搜索

            {

                Qnode b; //新节点加入优先队列

                for (k = 1; k <= n; k++)
                    b.x[k] = x[k];

                b.i = i + 1;

                b.f = f + c[i][x[i]];

                b.pot = up;

                Q.Add(b);
            }
        }

        Q.Delete(E); //取出下一个节点，更新状态变量i、f、x

        i = E.i;

        f = E.f;

        for (k = 1; k <= n; k++)
            x[k] = E.x[k];
    }
}

int main()

{

    MaxLoading();

    for (int k = 1; k <= n; k++)
        cout << x[k] << " ";

    cout << endl;

    cout << f;

    return 0;
}