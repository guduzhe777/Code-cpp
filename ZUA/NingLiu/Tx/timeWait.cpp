#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> time(n , 0);
    vector<int> windows(s, 0);
    vector<vector<int>> windowsSort(s,vector<int>());
    for (int i = 0; i < n; i++)
        cin >> time[i];
    sort(time.begin(), time.end(), less<int>());
    
    double sum = 0;
    for (int j = 0; j < n; j++)
    {
        windows[j % s] +=   time[j];
        windowsSort[j % s].push_back(j);
        sum += windows[j % s];
    }
    
    
    sum /= 1.0 * n;
    cout <<  sum << endl;
    for(int i = 0;i<s;i++)
    {
        cout<<i+1<<"窗口等待用户为:";
        while(windowsSort[i].size())
        {
            int x = windowsSort[i].back();
            windowsSort[i].pop_back();
            
            cout<<x+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}