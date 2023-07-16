#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int t;
int a, b, c;
ll k;
void sovle()
{
    cin >> a >> b >> c >> k;
    if (a > c || b > c)
        cout << "-1\n";
    else
    {
        ll cnt = 0;
        bool si = false;
        int aa = 1, bb = 1, cc = 1;
        for (int i = 1; i < a; i++)
            aa *= 10;
        for (int i = 1; i < b; i++)
            bb *= 10;
        
        for(int i = aa;(int)log10(i) + 1==a;i++)
        {
            for(int j = bb;(int)log10(j) + 1 == b;j++)
            {
                if((int)(log10(i + j) + 1) == c)
                {
                    cnt++;
                    if(cnt == k) 
                    {
                        cout<<i<<" + "<<j<<" = "<<i + j<<"\n";
                        si = true;
                        break;
                    }
                }else if((int)(log10(i + j) + 1) > c)
                {
                    break;
                }
            }
            if(si) break;
        }
        if(!si) cout<<"-1\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--)
        sovle();

    return 0;
}