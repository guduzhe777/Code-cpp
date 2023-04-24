#include<bits/stdc++.h>

using namespace std;
struct cmp{
    bool operator() (char a,char b )
    {
        return a>b;
    }
};
set<char,cmp> st; 
int main()
{
    char ch;
    while((ch = getchar()) != '\n')
    {
        st.insert(ch);
    }
    for(auto & v: st)
    {
        printf("%c",v);
    }

    return 0;
}