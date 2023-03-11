#include<bits/stdc++.h>

using namespace std;
string str;
bool str_cmp(char a,char b)//sort 直接给元素
{
    return a - b < 0;
}
int main()
{
    getline(cin,str);
    int sz = str.length();
    sort(&str[0],&str[0]+sz,str_cmp);
    cout<<str<<endl;
    return 0;
}