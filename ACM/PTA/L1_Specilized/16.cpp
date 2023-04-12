#include<bits/stdc++.h>

using namespace std;

int men,women,child;
bool si = false;
int n;
int main()
{
    //men + women + child = n
    //6 men + 4 women + child  = 2 * n
    cin>>n;
    for( men = 0;men<=n;men++)
    {
        for(women = 0;women<=n;women++)
        {
            child = n - men - women;
            if(6 * men + 4*women + child  == 2 * n)
            {
                si = true;
                printf("men = %d, women = %d, child = %d\n",men,women,child);
            }
        }
    }
    if(!si)
    {
        printf("None\n");
    }
    return 0;
}