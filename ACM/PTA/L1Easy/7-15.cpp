#include<bits/stdc++.h>

using namespace std;
int n;
double grade;
double res;
int main()
{
    cin>>n;
   for(int i = 0;i<n;i++)
   {
       cin>>grade;
       if(grade>=60) res++;
   }
    cout<<fixed<< setprecision(2)<<(res/n);

    return 0;
}