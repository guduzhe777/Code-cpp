#include <bits/stdc++.h>

using namespace std;

int n, m;
stack<int> st1, st2;

int main()
{
    cin >> n >> m;
    int v = min(n, m);
    while (1)
    {
        char ch;
        cin >> ch;
        if (ch == 'T')
        {
            break;
        }
        else if (ch == 'A')
        {
            int num;
            cin >> num;
            if (st1.size() < v)
            {
                st1.push(num);
            }
            else
            {
                if (st2.empty())
                {
                    while (!st1.empty())
                    {
                        st2.push(st1.top());
                        st1.pop();
                    }
                    st1.push(num);
                }
                else
                {
                    cout << "ERROR:Full"
                         << "\n";
                    continue;
                }
            }
        }
        else if (ch == 'D')
        {
            if (st1.empty()&&st2.empty())
            {
                cout << "ERROR:Empty"
                     << "\n";
                continue;
            }
            if (st2.empty())
            {
                while (!st1.empty())
                {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            int top = st2.top();
            st2.pop();
            cout << top << "\n";
        }
    }

    return 0;
}