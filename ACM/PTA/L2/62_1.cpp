#include <bits/stdc++.h>

using namespace std;

//优先队列 小顶堆排序
typedef pair<string, int> PSI;

struct cmp
{
    bool operator()(PSI a, PSI b)
    {
        return a.second > b.second;
    }
};
priority_queue<PSI, vector<PSI>, cmp> q;

int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        if (s1 == "PUT")
        {
            string s2;
            int clas;
            cin >> s2 >> clas;
            q.push({s2, clas});
        }
        else
        {
            if (q.empty())
            {
                printf("EMPTY QUEUE!\n");
                
            }else{
                PSI v = q.top();
                q.pop();
                cout<<v.first<<"\n";
            }
        }
    }

    return 0;
}