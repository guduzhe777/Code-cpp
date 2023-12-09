#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool si[100];

string s;
int n;
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>s;
        int x = 0;
        for(int i = 0;i<s.length();i++)
        {
        	x += s[i] - '0';
		}
		if(x % 3 == 0)
		{
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
    }
    

    return 0;
}
