#include<bits/stdc++.h>

using namespace std;
struct num{
    int c,d;
    int s;
};
const int N = 10e7;
num num1[2000];//存储？num[i] c d 一共有n种组合
int n;
bool cmp_num(const num &n1,const num &n2)
{
    if(n1.s <n2.s) return true;
    if(n1.s == n2.s)
    {
    	if(n1.c < n2.c) return true;
    	if(n1.c == n2.c)
    	{
    		if(n1.d<n2.d) return true;
		}
	}
	return false;//确保 排序 1  2  3   1 2 4情况 保证 联合主键  第一个 输出法 小的在前 
}
bool check(int mid,int target)
{
	if(num1[mid].s>=target) return true;
	return false;
}
int main()
{
    cin>>n;
    int i = 0;
    for(int c = 0;c * c<=n;c++)
    {
        for(int d = c;c * c + d* d<=n;d++)
        {
            int c1 = c * c;
            int d1 = d * d;
            int s = n - c1 - d1;
            num1[i].s = s;
            num1[i].c = c;
            num1[i].d = d;
            i++;
        }
    }
    sort(num1,num1+i,cmp_num);
    for(int a = 0;a * a<=n;a++)
    {
    	for(int b = a;a * a+ b* b <= n;b++)
    	{
    		int sum = a * a+ b * b;
    		int l = -1,r = i;
    		while( l + 1 != r)//在有序数组中寻找 等于sum的s 
    		{
    			int mid = (r - l)/2+l;
    			if(check(mid,sum)) r = mid;
    			else{
    				l = mid;
				}
			}
			if(sum == num1[r].s)
			{
				cout<<a<<" "<<b<<" "<<num1[r].c<<" "<<num1[r].d<<endl;
				return 0;
			}
		}
		
	}
	
    return 0;
}