

// 1.绝对值最大：0 9 上面变成0 一定变小 下面变成9一定变大
// 2.在保证第一个不同的时候 后面值随便取（因为前面已经确定小）
//所以即补前导0 找第一个不同 第一个不同以后 相差都为最大值9！

#include <bits/stdc++.h>

using namespace std;

int t;
string l, r;
void sovle()
{
    cin >> l >> r;
    while (l.length() < r.length())
        l = "0" + l;
    while (!l.empty() && l[0] == r[0])
        l.erase(l.begin()), r.erase(r.begin());
    int ans = 0;
    if (!l.empty() && !r.empty())
    {
        ans = 9 * (int)(l.length() - 1);
        ans += r[0] - l[0];
    }
    cout << ans << "\n";
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