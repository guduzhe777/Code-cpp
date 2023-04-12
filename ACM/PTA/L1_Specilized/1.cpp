#include<bits/stdc++.h>

using namespace std;

struct stu{
    string num;
    string name;
    int grade;
};
stu maxStu;
int n;
int main()
{

    cin>>n;
    for(int i = 0;i<n;i++)
    {
        string s1,s2;
        int g1,g2,g3,sum;
        cin>>s1>>s2>>g1>>g2>>g3;
        sum = g1 + g2 + g3;
        if(maxStu.grade<sum)
        {
            maxStu.num = s1;
            maxStu.name = s2;
            maxStu.grade = sum;
        }
    }
    cout<<maxStu.name<<" "<<maxStu.num<<" "<<maxStu.grade;

    return 0;
}