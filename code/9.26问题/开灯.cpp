#include<iostream>


using namespace std;



int main()
{
	///����һ����С����
	//���������±� % 1 --- n  ��Ϊ0 ȡ��
	int n,k;	
	cin >> n >> k;
	int arr[1000] = {0}; 
	
	for(int j = 1;j<=k;j++)
		{
			for(int i = 0;i< n;i++)
			{
				if( (i+1) % j  == 0)
				{
					arr[i] = ~arr[i]; //0ȡ��Ϊ���ֵ 
					//��� 1  
					
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
