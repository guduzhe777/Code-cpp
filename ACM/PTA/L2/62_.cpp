#include<bits/stdc++.h>

using namespace std;

typedef pair<string,int> PIS;
struct cmp1{
    bool operator()(PIS &a,PIS &b)
    {
        return a.second>b.second;
    }
};
priority_queue<PIS,vector<PIS>,cmp1 > q; 
int n;
int main()
{

    cin>>n;
    while(n--)
    {
        string s1;
        cin>>s1;
        if(s1 == "PUT")
        {
            string s1;
            int clas;
            cin>>s1>>clas;
            q.push({s1,clas});
        }else{
            if(q.empty())
            {
                printf("EMPTY QUEUE!\n");

            }else{
                PIS tem = q.top();
                q.pop();
                cout<<tem.first<<" "<<tem.second<<"\n";
            }
        }
    }


    return 0;
}


