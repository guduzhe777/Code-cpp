#include<bits/stdc++.h>
using namespace std;

const int N =  102;
char a[N];
char b[N];
int main()
{
    scanf("%s",&a);
    scanf("%s",&b);
    int cnt = 0;
    int sz = strlen(a);
    for(int i = 0;i<sz - 1;i++)
    { 
        if(a[i] != b[i])
        {
            a[i] = b[i];
            cnt++;//不同
            if(a[i+1] == '*')
            {
                a[i+1] = 'o';
            }
            else{
                a[i+1] = '*';
            }

        }
    }   
    cout<<cnt<<endl;
    return 0;
}