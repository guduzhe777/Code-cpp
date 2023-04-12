#include <bits/stdc++.h>
using namespace std;
int m, n, k;
bool isValid()
{
    int t = 1;
    stack<int> sk;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int data;
        cin >> data;
        if (t < data)//3竟然出栈了 1 - data 都入栈
        {            //入栈 且 确定 等待入栈点
                    //准备入 2  输出  7
                    //将之间点 放进去
            for (int j = t; j <= data; j++)
            {
                sk.push(j);
            }
            //t为 未入栈的 开始点
            t = data + 1;
            if (sk.size() > m)//可以入栈 需要保持容量
                flag = false;
        }   
        //准备入栈点 和 出栈点 相同 则 准备入栈的点进去又出来  下一个 准备入栈点为t++
        if (data == t)      //
        {
            t++;
            continue;
        }
        //围绕准备入栈点 与 输出点的关系 进行判断
        //
        //准备入栈点 大于 出栈的该点  5    2  除非 栈顶元素 为data 才可以出 
        if (!sk.empty() && data == sk.top())
        {
            sk.pop();
            continue;
        }
        //若栈顶元素 不为 data  t>data时候 5  2不是栈顶 2怎么输出呢
        flag = false;
    }
    if (flag)
        return true;
    else
        return false;
}
int main()
{
    cin >> m >> n >> k;
    while (k--)
    {
        if (isValid())
            puts("YES");
        else
            puts("NO");
    }
}