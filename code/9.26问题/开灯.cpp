#include<iostream>


using namespace std;



int main()
{
	///创建一定大小数组
	//基于数组下标 % 1 --- n  若为0 取反
	int n,k;	
	cin >> n >> k;
	int arr[1000] = {0}; 
	
	for(int j = 1;j<=k;j++)
		{
			for(int i = 0;i< n;i++)
			{
				if( (i+1) % j  == 0)
				{
					arr[i] = ~arr[i]; //0取反为最大值 
					//异或 1  
					
				}
			}
			
		}
	for(int i = 0;i<n;i++)
	{
		if(arr[i])
		{
			printf("%d ",i + 1 );
		}
	}
	return 0;
}
