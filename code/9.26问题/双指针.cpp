#include<iostream>
//#include<cstring>
#include<string.h>
using namespace std;


int main()
{
//	char ch[81];
//	scanf("%s",ch);	
//	int len = strlen(ch); 
	string ch;
	cin>>ch;
	int len=ch.size();
	
	for(int i = 0;i<len;i++)
	{
		for(int j = 1;j<len;j++)
		{
			if(ch[i] == ch[j])
			{
				i++;
				j++;
			}
		}
	}
	
	
	return 0;
}
