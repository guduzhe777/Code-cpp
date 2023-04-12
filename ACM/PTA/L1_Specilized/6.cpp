#include<bits/stdc++.h>

using namespace std;
//x1 * x2
//a + b i  c+  di
//a * c + a d i + b ci + b * d i * i
//a * c - b * d + (a * d + b * c)i

///a + c   (b + d ) i 

int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;

    printf("addition of complex is %lf+%lfi\n",a + c,b + d);
    printf("product of complex is %lf+%lfi\n",a*c-b*d,a* d+b*c);    
    return 0;
}