#include<stdio.h>
int main()
{
    int answer[256],guess[256];
    int game=0;
    while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0) break;
 
		game++;
		printf("Game %d:\n",game);
		
		for(int i=0;i<n;i++)
			scanf("%d",&answer[i]);
		for(;;)
		{
			for(int i=0;i<n;i++)
				scanf("%d",&guess[i]);
 
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(guess[i]!=0)
					count++;
			}	
			if(count==0) 
				break;
				
			int a=0;
			for(int i=0;i<n;i++)
			{				
				if(answer[i]==guess[i])
					++a;
			}
 
			int b=0;
			for(int j=1;j<=9;j++)
			{
				int c1=0, c2=0;
				for(int i=0;i<n;i++)
				{
					if(answer[i]==j) ++c1;
					if(guess[i]==j) ++c2;
				}
				if(c1<c2)
					b=b+c1;
				else
					b=b+c2;
			}
            printf("(%d,%d)\n",a,b-a);	
		}
    }
    return 0;
}
