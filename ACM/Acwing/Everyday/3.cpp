#include<bits/stdc++.h>


using namespace std;




//双指针 
int cnt ;// cnt = j 需要删除j个 

int t;
int si;
string s1,s2;

int main()
{
    scanf("%d",&t);
    si = t;
    while(t--)
    {
        int i,j;
        i = j = 0;

        cin>>s1;
        cin>>s2;
        cnt = 0;//不同个数
        int sz1 = (int) s1.length(),sz2 = (int)s2.length();


        while(i<sz1&&j<sz2)
        {
            if(s1[i] == s2[j])
            {
                i++,j++;
            }
            else if(s1[i] != s2[j])
            {
                cnt++;
                j++;
            }
        }
        // Case #1: 1
        // Case #2: IMPOSSIBLE
        if(i == sz1)
        {
            cnt = sz2 - j + cnt;
            printf("Case #%d: %d\n",si - t,cnt);
        }else{
            printf("Case #%d: IMPOSSIBLE\n",si - t);
        }
    }


    return 0;
}