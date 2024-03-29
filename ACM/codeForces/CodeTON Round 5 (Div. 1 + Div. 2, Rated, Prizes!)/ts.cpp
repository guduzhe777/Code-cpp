#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    i64 suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        suma += a;
    }
    for (int i = 0; i < m; i++) {
        int b;
        std::cin >> b;
        sumb += b;
    }
    if (suma > sumb) {
        std::cout << "Tsondu\n";
    } else if (suma < sumb) {
        std::cout << "Tenzing\n";
    } else {
        std::cout << "Draw\n";
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}