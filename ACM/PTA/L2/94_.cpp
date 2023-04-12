#include <bits/stdc++.h>

using namespace std;

int m, n, k;
bool Valid()
{
    stack<int> st;

    int t = 1; //开始入栈点
    bool si = true;//默认 可以输出
    for (int i = 0; i < n; i++)
    {
        int data;
        
        cin >> data;
        if (data > t)
        {
            for (int j = t; j <= data; j++)
            {
                st.push(j);
            }
            t = data + 1;

            if (st.size() > m)
            {
                si =  false;
            }
            st.pop();//将点输出
            continue;
        }
        if(data == t)
        {
            t++;
            continue;
        }
        if(data<t)//当输入小于 入栈临界点
        {
            if(!st.empty()&&st.top() == data)
            {
                st.pop();
                continue;
            }else{
                //如果空 / 栈顶 不是输出元素
                si =  false;
            }
        }
        
    }
    if(si) return true;//若不存在 输出栈顶错误  容量过载就欧克
    else{
        return false;
    }
}
int main()
{
    cin >> m >> n >> k; ///堆栈量  个数  序列数
    while (k--)
    {
        if (Valid())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}