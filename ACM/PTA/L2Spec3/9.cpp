#include<bits/stdc++.h>


using namespace std;

///俩栈模拟队列
//小的栈 出栈  大栈 存储
int n,m;
int main()
{
    cin>>n>>m;
    getchar();
    stack<int> a,b;
    char ch;
    while((ch = getchar()) != 'T')
    {
        
        if(ch == 'A')
        {
            int x;
            cin>>x;
            if(a.size()==m&&b.empty())
            {
                while(a.size())
                {
                    int top = a.top();
                    a.pop();
                    b.push(top);
                }
                
            }else if(a.size() == m && !b.empty())
            {
                printf("ERROR:Full\n");
                continue;
            }
            a.push(x);
            
        }else if(ch == 'D')
        {
            if(b.size())
            {
                int top = b.top();
                b.pop();
                printf("%d\n",top);
            }else if(!b.size()&&!a.empty())
            {
                while(a.size())
                {
                    int top = a.top();
                    a.pop();
                    b.push(top);
                }
                int top = b.top();
                b.pop();
                printf("%d\n",top);
            } else if(a.empty()&&b.empty())
            {
                printf("ERROR:Empty\n");
                continue;
            }
        }
    }
        

    return 0;
}