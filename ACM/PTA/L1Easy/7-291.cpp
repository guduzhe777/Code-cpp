#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[81];
	while(cin.getline(a,80))
    {

	
		int m=strlen(a);
		
		char b[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		int c[52]={0};
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<52;j++)
			{
				if(a[i]==b[j])
				{
					c[j]++;
					break;
				}
			}
		}
		int t=0;
		for(int i=51;i>=0;i--)
		{
			if(c[i]!=0)
			{
				t=i;
				break;
			}
		}
		int s=0;
		for(int i=0;i<t;i++)
		{
			if(c[i]!=0)
			{
				s++;
				if(s==10)
				{
				    printf("%c--%d",b[i],c[i]);	
				}
				else
				{
				
				    printf("%c--%d ",b[i],c[i]);
				}
			}
			
			if(s==10)
			{
			     cout<<endl;
			     s=0;
			}
		}
		if(c[t]!=0)
		{
		
		    printf("%c--%d\n",b[t],c[t]);
		}
    }
}
