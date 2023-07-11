#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
 
    int tt;
    cin >> tt;
 
    while (tt--) {
        vector<pair<int, ll> > vct;
        int n, m, h;
        cin >> n >> m >> h;
        pair<int, ll> key;
        for (int i = 0; i < n; ++i) {
            vector<int> a(m);
            for (int j = 0; j < m; ++j) {
                cin >> a[j];
            }
            sort(all(a));
            ll t = 0;
            ll fine = 0;
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (t + a[j] > h) {
                    break;
                }
                ++cnt;
                t += a[j];
                fine += t;
            }
            pair<int, ll> p = {-cnt, fine};
            vct.pb(p);
            if (i == 0) {
                key = p;
            }
        }
        sort(all(vct));
        for (int i = 0; i < sz(vct); ++i) {
            if (vct[i] == key) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
 
}