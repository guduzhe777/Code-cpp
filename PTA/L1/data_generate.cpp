#include<bits/stdc++.h>
#define N 1000
using namespace std;

//�����Ǵ���  ������ÿ�β���һ������ 
void generate_data() //��β�������? ѭ����������  ���뵽input.txt�� 
{
	ofstream fout("input.txt"); 
	int n = rand() % 98 + 1;
	fout<< n <<endl;
	for(int i = 0;i<n;i++)
	{
		int x = rand() % 1000 + 1;
		fout<<x<<endl;
	}
		
	
	fout.close();
}

int main()
{
	//��������
	for(int i = 0;i<N;i++)
	{
		printf("generate %d:\n",i);
		generate_data();
		//���ô���  ��������� �Ƚ�һ��
		system("7-53.exe < input.txt > web_output.txt");
		//���� ���� ��� 
		system("7-53my.exe < input.txt > my_output.txt"); 
		//�Ƚ��ж�
		if(system("fc web_output.txt my_output.txt") )
		{
			//system �ҵ����� --- 1  1�ҵ��˲��� 
			 getchar(); 
		}
		
	 } 
	
	return 0;
}

