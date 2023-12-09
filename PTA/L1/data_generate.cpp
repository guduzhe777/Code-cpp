#include<bits/stdc++.h>
#define N 1000
using namespace std;

//外面是次数  里面是每次产生一个数据 
void generate_data() //如何产生数据? 循环产生数字  输入到input.txt中 
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
	//产生数据
	for(int i = 0;i<N;i++)
	{
		printf("generate %d:\n",i);
		generate_data();
		//调用代码  生成输出后 比较一下
		system("7-53.exe < input.txt > web_output.txt");
		//程序 输入 输出 
		system("7-53my.exe < input.txt > my_output.txt"); 
		//比较判断
		if(system("fc web_output.txt my_output.txt") )
		{
			//system 找到差异 --- 1  1找到了差异 
			 getchar(); 
		}
		
	 } 
	
	return 0;
}

