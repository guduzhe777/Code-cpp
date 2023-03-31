#include<bits/stdc++.h>

using namespace std;
map<int,int> mp;//数值与下标 

//map 与 push_heap 维护
//
int n,m;
int main()
{
    cin>>n>>m;
    vector<int> heap;
    for(int i = 0,x;i<n;i++)
    {
        cin>>x;
        heap.push_back(x);
        push_heap(heap.begin(),heap.end(),greater<int>());
    }
    for(int i = 0;i<n;i++)
    {//堆的编号虽然从0开始  but 对应map的时候从1开始 等于对 堆重新编号。
    //利于求儿子父亲
        mp[heap[i]] = i + 1;//保证序号从1开始 利于 用儿子求父亲
    }
    for(int i = 0;i<m;i++)
    {
        int x,y;
        bool si = false;//默认命题错误
        string s;
        cin>>x;
        cin>>s;//2
        if(s == "is")
        {
            cin>>s;//
            cin>>s;//4
            if(s == "root")
            {
                if(mp[x] == 1)
                {
                    si = true;
                }
            }else if(s == "parent")
            {
                cin>>s;
                cin>>y;
                if(mp[x] == mp[y]/2)
                {
                    si = true;
                }
            }else if(s == "child")
            {
                cin>>s;
                cin>>y;
                if(mp[x]/2 == mp[y])
                {
                    si = true;
                }
            }
        }else if(s == "and")
        {
            cin>>y;
            getline(cin,s);
            if(mp[x]/2 == mp[y]/2)
            {
                si = true;
            }
        }
        if(si)
        {
            printf("T\n");
        }else{
            printf("F\n");
        }
    }
    return 0;
}