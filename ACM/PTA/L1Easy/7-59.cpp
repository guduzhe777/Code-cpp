#include<bits/stdc++.h>
#define pi  3.1415926
using namespace std;
double a,b;
int d,f;
double m;//秒
double angle;
//x必须是弧度不能是角度角度转换弧度

double Re(double angle)
{
    return angle / 180 * pi;
}
int main()
{
    cin>>a>>b>>d>>f>>m;
    angle = d + f / 60.0 + m / 60.0 /60.0;
    angle = Re(angle);
    
    
    printf("%.2lf\n",(tan(angle) * a + b));
    
    return 0;
}