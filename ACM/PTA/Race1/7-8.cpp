#include<bits/stdc++.h> 
using namespace std;

int cnt;//max����
struct grade{
	int Tts,Pat;//���ݳɼ���pta�ɼ� 
}; 
const int N  = 10e5 + 10;
grade stu[N];
int n,k,s;
bool cmp_stu(const grade &stu1,const grade &stu2)
{
	if(stu1.Tts>stu2.Tts) return true;//���� ǿ��ǰ 
	if(stu1.Tts == stu2.Tts&&stu1.Pat<stu2.Pat) return true;//������� pat��������ǰ 
	return false; 
}

int main()
{
	cin>>n>>k>>s;
	for(int i = 1;i<=n;i++)
	{
		cin>>stu[i].Tts>>stu[i].Pat;//���� pat 
	}
	sort(stu+1,stu+n+1,cmp_stu); 
	for(int i = 1;i<=n;)  //����ÿ��ѧ������ 
	{
		if(stu[i].Tts<175) continue;
		while(k--)
		{
			int tem;
			cnt++;//>175 ����ǰ�治��ȵ� ����һ�� 
			tem = stu[i].Tts;
			int j = i;
			while(i<=n&&tem == stu[i].Tts) i++;
			//iָ��������
			
		}
	}
	return 0;
 } 
