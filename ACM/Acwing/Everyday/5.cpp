#include <bits/stdc++.h>

using namespace std;

int t;
int l;
int n;
int d;
char c;
int stD;  //标准 距离
char stC; //标准  方向

long long cnt; // cnt = j  跑了j圈
int main()
{
    scanf("%d", &t);
    int tem = t;
    while (tem--)
    {
        cnt = 0;
        stD = 0;
        stC = '*';

        scanf("%d%d", &l, &n); // 一圈距离 n段跑步情况
        for (int i = 0; i < n; i++)
        {
            scanf("%d %c", &d, &c);
            if (stD == 0)
            {
                cnt += d / l;
                stC = c;
                stD = d % l;
            }
            else if (stC == c)
            {
                cnt += (stD + d) / l;
                stD = (stD+d) % l;

            }
            else
            {
                if (stD >= d)
                {
                    stD -= d;
                }
                else
                {
                    stD = d - stD;
                    stC = c;

                    cnt += (stD) / l;
                    stD = stD % l;

                }
            }
        }
        printf("Case #%d: %lld\n",t-tem,cnt);
    }

    return 0;
}