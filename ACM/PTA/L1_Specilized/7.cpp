#include<bits/stdc++.h>

using namespace std;

struct stu{
    string num;
    string name;
    double avg;
};
const int N = 51;
stu stus[N];
bool cmp(stu &s1,stu &s2)
{
    return s1.avg>s2.avg;
}
int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        string num,name;
        int g1,g2,g3;
        cin>>num>>name>>g1>>g2>>g3;
        double avg = (1.0 *g1 + g2 + g3)/3;
        stus[i] = {num,name,avg};
    }
    sort(stus,stus+n,cmp);
    for(int i = 0;i<n;i++)
    {
        cout<<stus[i].num<<","<<stus[i].name<<",";
        printf("%.2lf\n",stus[i].avg);
        
    }
        
    
    return 0;
}