#include<bits/stdc++.h>

using namespace std;

//格局小了。。。。。
//计算器符号 归符号
//一定是整数类型的 就当作整数输入比如 计算器 ，，
//能不用字符串处理就不要用

//有一定规律的 字符串 可以用整数类型读
int a,b;
char ch;
int ans;
int main()
{
    cin>>a;
    bool si = true;
    while((ch = getchar()) != '=')
    {
        cin>>b;
        switch(ch)
        {
            case '+':
                a +=  b;
                break;
            case '-':
                a = a - b;
                break;
            case '*':
                a = a * b;
                break;
            case '/':
                if(b == 0)
                {
                    
                    printf("ERROR\n");
                    return 0;
                }
                a = a / b;
                break;
            default: 
                printf("ERROR\n");
                return 0;
        }
    }

    printf("%d\n",a);
    return 0;
}