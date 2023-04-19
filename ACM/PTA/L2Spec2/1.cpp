#include<bits/stdc++.h>

using namespace std;


int n;
int main()
{
	queue<int> a,b;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x % 2)
		{
			a.push(x);
		}else{
			b.push(x);
		}
	}
	int cnt;
	bool fir = true;
	while(!a.empty()&&!b.empty())
	{
		cnt = 1;
		while(cnt <= 2&&!a.empty())	
		{
			cnt++;
			int goal = a.front();
			a.pop();
			if(fir)
			{
				fir = false;
				printf("%d",goal);
			}else{
				printf(" %d",goal);
				}
		}
		if(!b.empty())	
		{
			int goal = b.front();
			b.pop();
			if(fir)
			{
				fir = false;
				printf("%d",goal);
			}else{
				printf(" %d",goal);
				}
		}
	}
	while(!a.empty())	
	{
		int goal = a.front();
		a.pop();
		if(fir)
		{
			fir = false;
			printf("%d",goal);
		}else{
			printf(" %d",goal);
			}
	}
	while(!b.empty())	
	{
		int goal = b.front();
		b.pop();
		if(fir)
		{
			fir = false;
			printf("%d",goal);
		}else{
			printf(" %d",goal);
			}
	}
	return 0;
 } 
