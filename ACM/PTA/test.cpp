/*
提交时间    状态  分数  题目  编译器 耗时  用户
2018/7/5 09:47:48   答案正确    25  7-21    C++ (g++)   3 ms    17204111
测试点 结果  耗时  内存
0   答案正确    3 ms    384KB
1   答案正确    3 ms    384KB
2   答案正确    3 ms    384KB
3   答案正确    2 ms    384KB
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
stack <double> st;
int main()
{
    string s;
    getline(cin, s);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            double mul = 10, num = s[i] - '0';
            for (i--; i >= 0; i--)
            {
                if (isdigit(s[i]))
                {
                    num += (s[i] - '0') * mul;
                    mul *= 10;
                }
                else if (s[i] == '.')
                {
                    num /= mul;
                    mul = 1;
                }
                else if (s[i] == '-')
                    num = -num;
                else
                    break;
            }
            st.push(num);
        }
        else if (s[i] != ' ')   //else
        {
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
                {
                    if (b == 0)
                    {
                        cout << "ERROR";
                        return 0;
                    }
                    sum = a / b;
                }
            }
            st.push(sum);
        }
    }
    printf("%.1lf", st.top());
}