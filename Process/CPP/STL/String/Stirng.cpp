#include<bits/stdc++.h>
#include<string>
using namespace std;
string str1  = "abbc";
string str2 = "ab";
int main()
{
    int index = 0;
    index = str1.find(str2,index);
    cout<<index;

    return 0;
}