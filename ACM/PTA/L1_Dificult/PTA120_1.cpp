#include<bits/stdc++.h>

using namespace std;
//十进制转化其他 
int res;
const int N = 10010;
int w[N];
int main()
{
	cin>>res;
	int i;
	for( i = 0;res;i++)
	{
		w[i] = res % 26;
		res /= 26;
	}
	//i为长度 
	for(int j = i-1;j>=0;j--)
	{
		char ch = ('a' + w[j] - 1);
		printf("%c",ch);
	}
	cout<<endl;
	return 0;
}
