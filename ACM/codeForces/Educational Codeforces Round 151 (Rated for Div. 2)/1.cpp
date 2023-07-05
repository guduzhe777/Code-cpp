#include <bits/stdc++.h>

using namespace std;

int t;
int n, k, x;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &n, &k, &x);
        if (x != 1)
        {

            cout<<"YES"<<"\n";
            cout<<n<<"\n";
            for (int i = 0; i < n; i++)
            {
                cout<<1<<" ";
            }
            cout<<"\n";
        }
        else 
        {
            if (k == 1)
            {
                cout<<"NO"<<"\n";
           
            }
            else if (n % 2 == 0)
            {
                cout<<"YES"<<"\n";
                cout<<n/2<<"\n";
                for (int i = 0; i < n/2; i++)
                {
                    cout<<2<<" ";
                }
                cout<<"\n";
                
            }else if (n % 2 == 1)
            {
                if (k >= 3)
                {
                    
                    cout<<"YES"<<"\n";
                    cout<<n/2<<"\n";
                    cout<<3<<" ";
                    for(int i = 1;i<n/2;i++)
                    {
                        cout<<2<<" ";
                    }
                    cout<<"\n";
                    
                }
                else
                {
                    cout<<"NO"<<"\n";
                }
            }
            
        }
    }

    return 0;
}