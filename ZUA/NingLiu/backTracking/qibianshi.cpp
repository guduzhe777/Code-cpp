#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
int ch[9];
char ch_char[9];

bool si = false;
int ans = 0;
// curI : 当前选择点
//当全部满了？
//一直填  直到不能填为止

void brackTrack()
{
    if (ans == 7)
    {
        si = true;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (!ch[i]) // i位置能放
        {
            if (!ch[(i + 2) % 8 + 1])
            {
                ch[(i + 2) % 8 + 1] = 1;
                ans++;
                brackTrack();
                if (si)
                    return;
                ch[(i + 2) % 8 + 1] = 0;
                ans--;
            }

            if (!ch[(i + 4) % 8 + 1])
            {
                ch[(i + 4) % 8 + 1] = 1;
                ans++;
                brackTrack();
                if (si)
                    return;
                ch[(i + 4) % 8 + 1] = 0;
                ans--;
            }
        }
    }
}
int main()
{
    cin >> n;
    getchar();
    while (n--)
    {
        ans = 0;
        si = false;
        cin >> ch_char;
        getchar();
        for (int i = 0; i < 8; i++)
        {
            ch[i] = ch_char[i] - '0';
        }
        for (int i = 0; i < 8; i++)
        {
            if (ch[i])
            {
                ans++;
            }
        }

        if (ans == 7)
            cout << "Yes" << endl;
        else
        {
            brackTrack();
            if (si)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
//错误点：误以为子集树 每次选择一个方向投 然后每次都是 选择一个方向投 其实 选一个方向投后 还可以从头开始向下投 
//只要全部投完到7个(进入函数先判断一下)即可


