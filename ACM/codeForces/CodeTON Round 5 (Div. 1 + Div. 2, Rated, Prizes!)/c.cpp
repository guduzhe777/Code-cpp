#include <bits/stdc++.h>
 
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const int inf = (int) 1e9;
    vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      int v = dp[a[i]];
      dp[a[i]] = max(dp[a[i]], dp[0] - i);
      dp[0] = max(dp[0], v + i + 1);
    }
    cout << dp[0] << '\n';
  }
  return 0;
}