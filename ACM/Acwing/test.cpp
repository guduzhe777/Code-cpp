#include <bits/stdc++.h>

using namespace std;

const int N = 33;
char arr[N];
bool num[N];
int obs(bool a)
{
    return (a == true) ? 1 : 0;
}
int main()
{
    //输入二进制数字 cin需要空格。。。
    for (int i = 1; i <= 32; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= 32; i++)
    {

        if (arr[i] == '1')
        {
            num[i] = true;
        }
        else
        {
            num[i] == false;
        }
    }
  
    int sum = 0;
    int tem;
    for (int j = 0; j < 4; j++)
    {

        for (int i = 8 + j * 8; i >= 1 + j * 8; i--)
        {
            tem = obs(num[i]);
            sum += tem * pow(2, j * 8 + 8 - i);
        }

        if (j == 0)
        {
            printf("%d", sum);
        }
        else
        {
            printf(".%d", sum);
        }
        sum = 0;
    }
    return 0;
}