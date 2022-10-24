#include <iostream>

using namespace std;

class solution
{

    // kmp
    //子串的 前缀表 j 指向前缀表后一个  i指向该元素
public:
    int getPrefix(string s, int Prefix[])
    {

        Prefix[0] = -1;
        Prefix[1] = 0;
        int i = 1;
        int j = 0;
        while (i < s.length())
        {
            if (j == -1 || s[i] == s[j])
            {
                Prefix[++i] = ++j;
            }
            else
            {
                j = Prefix[j]; //前缀表的下一个
            }
        }
    }
    int kmp(string ss, string s)
    {
        int i = 0, j = 0, prefix[1001];
        int s_len = s.length();
        int ss_len = ss.length();
        getPrefix(s, prefix);
        while ((j < s_len) && (i < ss_len))
        {
            if (j == -1 || s[i] == s[j]) //说明第一个也不同那么 都++
            {
                ++i;
                ++j;
            }
            else
            {
                j = prefix[j]; //前缀表的下一个来比较
            }
        }
        if (j == s_len)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    string s, ss;
    cin >> ss >> s;
    solution a;
    cout << a.kmp(ss,s)<<endl;

    return 0;
}