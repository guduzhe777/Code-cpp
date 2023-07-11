#include <bits/stdc++.h>

using namespace std;

bool si; //默认没有人赢
char aa[4][4];
char stchar;

int t; // t次

int ans = 1; //几个标准符号
int main()
{

    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                cin >> aa[i][j];
        stchar = aa[1][1];
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (stchar == aa[i][1])
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }
        stchar = aa[1][1]; //默认参数
        ans = 0;
        for (int i = 1, j = 1; i <= 3, j <= 3; i++, j++)
        {
            if (aa[i][j] == stchar)
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }
        stchar = aa[1][1]; //默认参数
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (aa[1][i] == stchar)
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }

        stchar = aa[2][1]; //默认参数
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (aa[2][i] == stchar)
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }

        stchar = aa[3][1]; //默认参数
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (aa[3][i] == stchar)
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }

        stchar = aa[1][3]; //默认参数
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (aa[i][3] == stchar)
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }
        stchar = aa[1][3]; //默认参数
        ans = 0;
        for (int i = 3, j = 3; i & j; i--, j--)
        {
            if (stchar == aa[i][j])
                ans++;
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }
        stchar = aa[1][2];
        ans = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (stchar == aa[i][2])
            {
                ans++;
            }
        }
        if (ans == 3 && stchar != '.')
        {
            cout << stchar << endl;
            continue;
        }

        cout << "DRAW" << endl;
        static int k = 0;
        cout<<++k<<endl;
    }

    return 0;
}