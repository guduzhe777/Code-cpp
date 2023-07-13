#include<bits/stdc++.h>


using namespace std;


int n;
string s;
int index0,index1;
struct point{
    int maxlen;
    int maxindex;
};
point justy(int st,char ch)
{
    int len = 0;
    int index = -1;
    int maxlen = -1e9;
    int maxindex = -1;
    for(int i = st;i<(int)s.length();i++)
    {
        while(i<n && ch != s[i]) i++;
        bool fi = true;
        while(i<n && ch == s[i]) 
        {
            
            len++;
            if(fi)
            {
                index = i;
                fi = false;
            }
            i++;
        }
        if(maxlen<len)
        {
            maxlen = len;
            maxindex = index;
            len = 0;
            index = -1;
        }
    }
    point p;
    p.maxindex = maxindex;
    p.maxlen = maxlen;
    return p;
}
int main()
{
    cin>>n;
    cin>>s;
    point p0 = justy(0,'0');
    point p1 = justy(0,'1');
    //左看几个0  右看 几个0
    int lmax0 = 0,rmax0 = 0;
    for(int i = p1.maxindex;i>=0;i--)
    {
        if(s[i] == '0')
        {
            ++lmax0;
        }else{
            break;
        }
    }

    for(int i = p1.maxindex+p1.maxlen;i<(int)s.length();i++)
    {
        if(s[i] == '0')
        {
            ++rmax0;
        }else{
            break;
        }
    }
    cout<<max(p1.maxlen + max(lmax0,rmax0),p0.maxlen);

    return 0;
}