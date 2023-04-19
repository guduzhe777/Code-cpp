#include<bits/stdc++.h>

using namespace std;

string s;
int maxlen;
int main()
{
	getline(cin,s);
	for(size_t i = 0;i<s.length();i++)
	{
		int j = s.rfind(s[i]);
		int cnt = 0;
		bool sysme = true;//¶þÕß¶Ô³Æ 
		while(i<=j)
		{
			if(s[i] != s[j] && i != j)
			{
				sysme = false;
				break;
			}
			if(s[i] == s[j]&&i != j)
			{
				cnt += 2;
			}else if(i == j)
			{
				cnt++;
			}
			
			i++,j--;
		}
		if(sysme)
		{
			maxlen = max(maxlen,cnt);
		}
	}
	printf("%d",maxlen);
	return 0;
}
