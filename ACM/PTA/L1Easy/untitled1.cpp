#include<bits/stdc++.h>
using namespace std;

int repeat;
int h,m,s;
char ch;
int n;

int main()
{
	cin>>repeat;
	while(repeat--)
	{
		cin>>h>>ch>>m>>ch>>s;
		cin>>n;
		s += n;
		if(s>=60)
		{
			m += s / 60;
			s %= 60;	
		}
		if(m>=60)
		{
			h += m / 60;
			m %= 60;	
		}
		if(h>=24)
		{
			h %= 24;
		}
		
		printf("time: %d:%d:%d\n",h,m,s);
	}	
	return 0;
}
