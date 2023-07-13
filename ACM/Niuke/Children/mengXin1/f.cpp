#include<bits/stdc++.h>
#define int long long
 using namespace std;
 const int N=1e5+10;
 int n;
 int x;
vector<int> a;
 typedef long long ll;

void solve(){
	map<int, int>mp;    
    vector<int> b(a);
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++)mp[b[i]] = i ;//记录下标索引
 
    ll cnt = 0;
    for (int i = 0; i < a.size();i++)
    {
        if (a[i] == b[i])continue;
        swap(a[i], a[mp[a[i]]]);
        cnt++;
    }
    printf("%lld\n",cnt);
}
signed main(){
    
    cin>>n;
 	for(int i=0;i<n;i++){
 		scanf("%d",&x);
 		a.push_back(x);
    }
    solve();
 	return 0;
 } 