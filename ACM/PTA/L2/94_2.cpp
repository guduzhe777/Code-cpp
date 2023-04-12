#include<bits/stdc++.h>

using namespace std;


// 入栈点t
//data >t 放入
// data ==  t  放入又弹出
//data < t     栈顶弹出

int n,m,k;
bool Valid()
{
    int t = 1;
    stack<int> st;
    bool si = true;//合法序列
    for(int i = 0;i<n;i++)
    {
        int data;
        cin>>data;
        if(data>t)
        {
            for(int j = t;j<=data;j++)
            {
                st.push(j);
            }
            t = data + 1;
            if(st.size()>m)
            {
                si = false;
            }
            st.pop();
            continue;//下一个点
        }
        if(data == t)
        {
            t++;
            continue;//放入又弹出
        }
        if(data<t)
        {
            if(!st.empty()&&st.top() == data)
            {
                st.pop();
                continue;//栈顶元素
            }else{
                //不是栈顶
                si = false;
            }
        }
    }
    if(si) return 1;
    else{
        return 0;
    }

    
}
int main()
{

    cin>>m>>n>>k;
    while(k--)
    {
        if(Valid())
        {
            printf("%YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}