#include<bits/stdc++.h>
using namespace std;
long long n,a,b=1,c;

int main(){
    scanf("%d",&n);
    while(n--){
        printf("%d \n",a);
        c=a+b;
        a=b,b=c;
        cout<<c<<" "<<a<<" "<<b<<" "<<endl;
    }
}