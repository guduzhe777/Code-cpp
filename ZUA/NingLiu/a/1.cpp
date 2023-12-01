#include<bits/stdc++.h>

using namespace std;

void horit(int n,char a,char b,char c) //n个 借助b 从a移动到c  
{

    if(!n)
    {
        return;
    }
    horit(n-1,a,c,b);   //为了a->c 所以 n-1 a 到 b 
    cout<<a<<"->"<<c<<endl;
    horit(n-1,b,a,c);//n-1个在b了  需要将n-1个 移动到c
    
}

int main()
{
    int n;
    cin>>n;

    horit(n,'a','b','c');


    return 0;
}