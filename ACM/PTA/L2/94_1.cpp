#include<bits/stdc++.h>


using namespace std;



int n,m,k;


bool Valid()
{
    int t = 1;
    bool si = true;//合法序列
    stack<int> st;//存放入的点
    for(int i = 0;i<n;i++)
    {
        int data;
        cin>>data;
        if(t<data) //情况1 入栈点 t < data
        {
            for(int i = t;i<= data;i++)
            {
                st.push(i);
            }
            t = data + 1;
            if(st.size()>m)//如果 超过容量
            {
                si = false;
            }
            st.pop();
            
            continue;
        }
        if(t == data)//情况2
        {
            t++;
            continue;
        }
        if(t>data)//情况3
        {
            if(!st.empty()&&st.top() == data)
            {
                st.pop();
                continue;
            }else{
                si = false;
            }
        }
    }
    return si;
}
int main()
{
    cin>>m>>n>>k;

    while(k--)
    {
        if(Valid()) printf("YES\n");
        else{
            printf("NO\n");
        }
    }


    return 0;
}