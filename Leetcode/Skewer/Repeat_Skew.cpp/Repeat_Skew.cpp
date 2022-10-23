#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        return KMP(s,ss);
    }
    bool KMP(string s,string ss)
    {
        int i = 1,j = -1;//
        int next[1001];
        next[0] = -1;
        next[1] = 0;
        while(i<s.length())
        {
            if(j == -1 || s[j] == s[i]) //i指向该元素 判断这个串的最大前缀尾 保存在后面  
            {
                next[++i] = ++j;
            }
            else{
                j = next[j]; //始终指向 最大 次大 。。。前缀尾 借以判断是否相等
            }
        }
        //找到了next 
        i = 0,j = 1;
        int s_len = s.length();
        int ss_len = ss.length();
        while((i<s_len)&&(j<ss_len-1))
        {
            if((i == -1)||(s[i] == ss[j]))
            {
                ++i;
                ++j;
            }
            else{
                i = next[i];
            }
        }
        if(i == s.length())
        {
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Solution a;
    string s;
    cin >> s;

    if(a.repeatedSubstringPattern(s))
    {
        printf("Yes");
    }
    else{
        printf("No");
    }


    return 0;
}