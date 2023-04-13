#include<bits/stdc++.h>


using namespace std;

int get_fact(int a,int b)
{
    int stand = max(a,b);
    while(1)
    {
        if(!(stand % a)&&!(stand%b))
        {
            return stand;
        }
        stand++;
    }
}
int get_appro(int a,int b)
{
    if(a % b == 0) return b;
    if(b == 0)
    {
        return a;
    }
    get_appro(b,a % b);
}
struct  PII{
    int up,down;
    PII operator + (const PII &a)
    {
        int fact = get_fact(down,a.down);
        PII c = a;
        up *= fact / down;
        c.up *= fact / c.down;
        up = up + c.up;
        down = fact;
        int appro = get_appro(up,down);
        up /= appro;
        down /= appro;
        return (*this); //返回 PII类型 this为 指向pii的指针
    }
};
PII sum,number;
int n;

int main()
{

    cin>>n;
    int up,down;
    scanf("%d/%d",&up,&down);
    sum = {up,down};
    while(--n)
    {
        scanf("%d/%d",&up,&down);
        number = {up,down};
        sum = sum + number;
        auto &[v,w] = sum;
        
    }
    int withsoc = sum.up/sum.down;
    int frac = sum.up % sum.down;
    int appro = get_appro(frac,sum.down);
    if(frac&&withsoc)
    {
        printf("%d %d/%d",withsoc,frac/appro,sum.down/appro);
    }else if(!frac){
        printf("%d",withsoc);
    }else if(!withsoc)
    {
         printf("%d/%d",frac/appro,sum.down/appro);
    }
    return 0;
}