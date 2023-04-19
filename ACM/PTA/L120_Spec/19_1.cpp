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
typedef pair<int,int> PII;

PII sum,number;

int n;
void easy( PII&a )
{
    int appro = get_appro(a.first,a.second);
    a.first /= appro;
    a.second /= appro;
}
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
        int fact = get_fact(number.second,sum.second);
        number.first *= fact / number.second;
        sum.first *= fact / sum.second;
        sum.first += number.first;
        number.second = sum.second = fact;

        easy(sum);
    }
    int withsoc = sum.first/sum.second;
    int frac = sum. first % sum.second;
    int appro = get_appro(frac,sum.second);
    frac /= appro;
    sum.second /= appro;
    if(withsoc&&frac)
    {
        cout<<withsoc<<" "<<frac<<"/"<<sum.second;
    }else if(!withsoc)
    {
        cout<<frac<<"/"<<sum.second;
    }else if(!frac)
    {
        cout<<withsoc;
    }
    
    return 0;
}