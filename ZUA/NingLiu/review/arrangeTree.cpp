#include <bits/stdc++.h>
using namespace std;

int n;
char a[10] = {'a', 'b', 'b'};
bool shift(int k,int i)
{
    for(int j = k;j<i;j++)
    {
        if(a[j] == a[i]) return false;
    }
    return true;
}
// template<typename T>
int main()
{

    cin >> n;
    
    function<void(int)> fun = [&](int k)
    {
        //
        if (k == n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        for (int i = k; i < n; i++)
        {
            if (shift(k,i))
            {
                swap(a[k], a[i]);
                fun(k + 1);
                swap(a[i], a[k]);
            }
        }
    };

    fun(0);

    return 0;
}