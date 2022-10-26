#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
stack<double> st;
int isdigta(char x)
{
    if ((x >= '0') && (x <= '9'))
    {
        return 1;
    }
    return 0;
}
int main()
{
    //输入  从后到前扫描
    string s;
    double num;
    getline(cin, s);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        //判断数字
        ///符号

        if (isdigta(s[i]))
        {
            double pow = 10;  //对应   num是对应s[i]的值
            num = s[i] - '0'; //原本为字符//都会等于 第一个数字 等待 判断前面为 什么
            // for (int i = i - 1; i >= 0; i--)
            for (i--; i >= 0; i--) //每进行一次  i 指向的地方就向前走一步
            {

                if (isdigta(s[i]))
                {
                    num += (s[i] - '0') * pow;
                    pow *= 10; //这一次权重为10 下一个为100 （前一个符号为数字的时候就整体便是数字 有权重的）
                }
                else if (s[i] == '.')
                {
                    // num /= 10;
                    // num += s[i] - '0'; //小数点前移  加这个数字
                    //他只管自己的事情  如果 需要加法 是 上一层管的事情
                    num /= pow;
                    pow = 1;
                }
                else if (s[i] == '-')
                {
                    num = -num;
                }
                else
                    break;
            }
            //当这个数字前面 确实只有空格的时候就放进去吧
            st.push(num); //
        }
        else if (s[i] != ' ') //符号 //
        {                     //因为前缀计算 只能保证符号后面有>=两个数字 不能保证空格怎么样
            //所以会出现溢出现象

            //出栈 然后 计算
            double a, b, sum;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                sum = a + b;
                break;
            case '-':
                sum = a - b;
                break;
            case '*':
                sum = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    cout << "ERROR";
                    return 0;
                }
                sum = a / b;

                break;
            }             //计算完毕
            st.push(sum); //入栈
        }
    }
    //最后计算完进栈 结果在栈顶
    printf("%.1lf\n", st.top());
    return 0;
}
