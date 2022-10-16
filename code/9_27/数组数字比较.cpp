#include<iostream>

using namespace std;



int main()
{
	int n,total = 0,sum = 0,sign = 0;	//±êÖ¾Î» 
	scanf("%d",&n);
	int arr[n]; 
	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	total += arr[0];
	
	for(int i = 1;i<n;i++)
	{
		if(total != sum)
		{
			total += arr[i];
			sum -= arr[i-1];
	
		}
		else
		{
			cout << i <<endl;
			return 0;
		}
		
	}
	cout << "-1" <<endl;
	
	
	return 0;
	
 } 
