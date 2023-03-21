// //彩虹瓶的制作过程（并不）是这样的：先把一大批空瓶铺放在装填场地上
// //，然后按照一定的顺序将每种颜色的小球均匀撒到这批瓶子里。
// //彩虹瓶里要按顺序装 N 种颜色的小球（不妨将顺序就编号为 1 到 N）。
// //现在工厂里有每种颜色的小球各一箱，工人需要一箱一箱地将小球从工厂里搬到装填场地
// //。如果搬来的这箱小球正好是可以装填的颜色，就直接拆箱装填；
// //当一种颜色装填完以后，先看看货架顶端的一箱是不是下一个要装填的颜色，
// //如果是就取下来装填，否则去工厂里再搬一箱过来。：可能搬的并不是 需要的 而是他给的
// //
// //设 cnt 为需要的 数字
// //他会在 栈顶判断   ，
// //不行：//拿
// //      拿了不行 ：放到架子
// //          //若容量不行那么 愤怒 || 工厂没了 没找到cnt  那么 愤怒：
// //          //容量行  继续在工厂拿
// //      拿了行：cnt++，需要下一个
// //行：cnt++，需要下一个

// //一直装填 ， 工厂没了 没找到cnt  那么 愤怒：
// //愤怒：
// // 1.
// // 3、1、5、4、2、6、7 这个顺序发货 装填完 2 号颜色以后，不把货架上的多个箱子搬下来就拿不到 3 号箱
// //就不可能顺利完成任务。
// // 2.
// //如果要堆积的货物超过容量，工人也没办法顺利完成任务。
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int n, m, k; // 彩虹瓶的颜色数量 临时货架的容量 发货顺序
const int N = 10e3 + 10;
int f[N];

int main()
{
    cin >> n >> m >> k;
    while (k--)
    {
        stack<int> st;   //货架  最大m
        int nd = 1; //开始需要1 需要nd 数字
        int i = 0;
        int si = true; //可以完全放入
        for (i = 0; i < n; i++)
        {
            cin >> f[i]; //输入这个数字
        }
        for (int i = 0; i < n; i++)
        {
            if (nd == f[i]) //相等
            {
                nd++;
            }
            else
            {
                st.push(f[i]); //不等放入栈里
            }

            if (st.size() > m) //大于容量数量  //最后一个数字
            {
                si = false;
                break; //结束
            }
            if (st.empty()) //栈空 第一个不等 继续从 工厂拿
            {
                continue;
            }
            else
            {
                while (!st.empty() && nd == st.top()) //不空
                {
                    st.pop(); //拿出来 第一个
                    nd++;     //需要下一个
                }
            }
        }
        if (!st.empty()) //工厂都拿完了 栈还是 还有元素 很g
        {
            printf("NO\n");
            si = false;
        }
        if (si)
        {
            printf("YES\n");
        }
    }
    return 0;
}