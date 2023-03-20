#include<bits/stdc++.h> 
using namespace std;

int cnt;//max数量
struct grade{
	int Tts,Pat;//天梯成绩，pta成绩 
}; 
const int N  = 10e5 + 10;
grade stu[N];
int n,k,s;
bool cmp_stu(const grade &stu1,const grade &stu2)
{
	if(stu1.Tts>stu2.Tts) return true;//天梯 强在前 
	if(stu1.Tts == stu2.Tts&&stu1.Pat<stu2.Pat) return true;//天梯相等 pat分数少在前 
	return false; 
}

int main()
{
	cin>>n>>k>>s;
	for(int i = 1;i<=n;i++)
	{
		cin>>stu[i].Tts>>stu[i].Pat;//天梯 pat 
	}
	sort(stu+1,stu+n+1,cmp_stu); 
	for(int i = 1;i<=n;)  //对于每个学生处理 
	{
		if(stu[i].Tts<175) continue;
		while(k--)
		{
			int tem;
			cnt++;//>175 且与前面不相等的 多了一个 
			tem = stu[i].Tts;
			int j = i;
			while(i<=n&&tem == stu[i].Tts) i++;
			//i指向不相等情况
			
		}
	}
	return 0;
 } 
