#include <bits/stdc++.h>

using namespace std;

//栈

map<char, char> mp;
stack<char> st;
int main()
{

    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';
    //匹配关系
    string s;
    getline(cin, s);
    for (auto ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                printf("Extra right brackets\n");
                return 0;
            }
            if (mp[st.top()] == ch)
            {
                st.pop();
            }
            else
            {
                printf("Brackets not match\n");
                return 0;
            }
        }
    }

    if (!st.empty())
    {
        printf("Extra left brackets\n");
        return 0;
    }
    else
    {
        printf("Brackets match\n");
        return 0;
    }
    return 0;
}