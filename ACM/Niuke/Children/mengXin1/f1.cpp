#include<iostream>
 #include<vector>
 #include<algorithm>
 #include<map>
 using namespace std;
 const int N=10005;
 int n;
 int x;
vector<int> a;
 
int getMinSwaps(vector<int> &a)
{
    map<int, int>mp;    
    vector<int> b(a);
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++)mp[b[i]] = i ;//记录下标索引
 
    int cnt = 0;
    for (int i = 0; i < a.size();i++)
    {
        if (a[i] == b[i])continue;
        swap(a[i], a[mp[a[i]]]);
        cnt++;
    }
    return cnt;
}
void solve(){
	printf("%d\n",getMinSwaps(a));
}
int main(){
    cin>>n;
 	for(int i=0;i<n;i++){
 		scanf("%d",&x);
 		a.push_back(x);
	 }
	 solve();

 	return 0;
 } 