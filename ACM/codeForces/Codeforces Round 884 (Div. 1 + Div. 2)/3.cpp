
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
int t;
int n;
vector<int> a;
void justy()
{
    bool si = false;
    while (a[0] <= 0)
    {
        a.erase(a.begin());
    }
    while (a[a.size() - 1] <= 0)
    {
        a.erase(a.end() - 1);
    }
}
signed main()
{

    cin >> t;
    while (t--)
    {
        cin >> n;
        a.clear();
        bool si = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                si = true;
            }
            a.push_back(x);
        }
        if (si) //含有正数
        {
            justy();

            while (a.size() > 3)
            {
                ll min0 = 1e9 * 1e9;
                int index = -1;
                int j;
                for (j = 1; j < a.size() - 1; j++)
                {
                    if (a[j] < min0)
                    {
                        min0 = a[j];
                        index = j;
                    }
                }
                ll y = (ll)a[index - 1] + (ll)a[index + 1];
                a[index] = y;
                a.erase(a.begin() + index + 1);
                a.erase(a.begin() + index - 1);
            }
            //三个单独判断
            if (a.size() == 3)
            {
                ll y = (ll)a[0] + (ll)a[2];
                if (y >= a[1])
                {
                    a[1] = y;
                }
                a.erase(a.begin());
                a.erase(a.end() - 1);
            }

            ll max0 = -1e9 * 1e9;
            for (int i = 0; i < a.size(); i++)
            {
                max0 = max(max0, (ll)a[i]);
            }
            cout << max0 << endl;
        }
        else
        {
            //全负数咋办
            int max0 = -1e9*1e9;
            for (int i = 0; i < a.size(); i++)
            {
                max0 = max(max0, a[i]);
            }
            cout << max0 << endl;
        }
    }

    return 0;
}