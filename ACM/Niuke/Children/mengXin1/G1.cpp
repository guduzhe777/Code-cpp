#include<bits/stdc++.h>


using namespace std;


int n;
string s;
int index0,index1;

void justy()
{
    vector<int> a;
    int j = 0;//起始下标
    for(int i = 0;i<(int)s.length();i++)
    {
        //某一段0开始  1结束 1个数
        while(i<n && s[i] == '0') i++;
        j = i;//新起始下标
        while(i<n && s[i] == '1') i++;

        a.push_back(i - j); //1的个数
        

    }
    sort(a.begin(),a.end(),greater<int>()); //接起来 最多1字符串当尾部
    if(a.size()>=2)
    {
        cout<<a[0] + a[1]<<endl;
    }else if(a.size() == 0)
    {
        cout<<0<<endl;
    }else{
        cout<<a[0]<<endl;
    }
}
    
int main()
{
    cin>>n;
    cin>>s;
    
    justy();

    return 0;
}