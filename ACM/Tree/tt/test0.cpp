#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    
    for (int i = 0; i < a.size();i++)
    {
        b = a;
        cout << b[i] << " ";
    }
        return 0;
}
