#include<bits/stdc++.h>

using namespace std;

string str1,str2;
string s1, s2;

int main()
{
	cin>>str1>>str2;
	for(size_t i = 1;i<str1.length();i++)
	{
		if(str1[i]%2 == str1[i-1]%2) s1 += max(str1[i],str1[i-1]);
	}
	cout<<s1<<endl;
	return 0;
}
