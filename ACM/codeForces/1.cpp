#include <bits/stdc++.h>

using namespace std;

int t;
int n, k, x;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &n, &k, &x);
        if (x != 1)
        {

            printf("YES\n");
            printf("%d\n", n);
            for (int i = 0; i < n; i++)
            {
                if (i)
                {
                    cout<<"1"<<" ";
                }
                
            }
            cout<<"\n";
        }
        else if (x == 1)
        {
            if (k == 1)
            {
                printf("NO\n");
            }
            else if (n % 2 == 0)
            {
                printf("YES\n");
                printf("%d\n",n/2);
                for (int i = 0; i < n; i+=2)
                {
                    if (i)
                    {
                        printf(" 2");
                    }
                    else
                    {
                        printf("2");
                    }
                }
                printf("\n");
                
            }
            else if (n % 2 == 1)
            {
                if (k >= 3)
                {
                    
                    printf("YES\n");
                    printf("%d\n",n/2);
                    printf("3 ");
                    for(int i = 1;i<n;i+=2)
                    {
                        printf("2 ");
                    }
                    printf("\n");
                    
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }

    return 0;
}