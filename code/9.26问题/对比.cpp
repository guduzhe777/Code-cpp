#include<iostream>


using namespace std;



int main()
{
	int n,sum_same = 0,sum_dif = 0,sum;
	scanf("%d",&n);
	
	int arr1[1000];
	for(int i = 0;i< n ;i++)
		{
			scanf("%d",&arr1[i]);
		}
	while(1)
	{
		//��������� 
		//����²����� 
		//�ж�0 
		// һ��ָ���ж�  
		//+˫ָ�� �ж� �оͿ�����ͣ 
		//������һ���ж�
		
		int arr2[1000];
		
		for(int i = 0;i< n ;i++)
		{
			scanf("%d",&arr2[i]);
			sum += arr2[i];
		}
		if(!sum)
		{
			return 0;
		}
		
		for(int i = 0;i<n;i++)
		{
			if(arr1[i] == arr2[i])
			{
				sum_same++; 
				
			}
		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if((arr1[i] == arr2[j])&&(j != i))
				{
					sum_dif++;
				}
			}
		}
		cout<< sum_same << sum_dif-sum_same <<endl;
		sum_same = 0,
		sum_dif = 0;
		}	
	return 0;
 } 
