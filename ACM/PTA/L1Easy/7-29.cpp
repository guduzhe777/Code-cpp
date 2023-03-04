#include<bits/stdc++.h>
using namespace std;
const int N = 128;
int word[N];
int main()
{
    string s;
    getline(cin, s);
    for (char i : s)
        word[i]++;
    vector<pair<char,int>> ans;
    for (int i = 0, cnt = 0; i < N; i++)
       if (word[i] && i!=' ') {
           ans.push_back({i, word[i]});
       } 
    for (int i = 0; i < ans.size(); i++)
        printf("%c--%d%c", ans[i].first, ans[i].second, " \n"[(i+1)%10==0||i==ans.size()-1]);
//     for (int i = 0, cnt = 0; i < N; i++)
//        if (word[i] && i!=' ') {
//            cnt++;
//            printf("%c--%d%c", i, word[i], " \n"[cnt%10==0]);
//        }    
    return 0;
}