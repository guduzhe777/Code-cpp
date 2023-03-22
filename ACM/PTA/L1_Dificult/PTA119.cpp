//无论用户说什么，首先把对方说的话在一行中原样打印出来；(保存输出)
//消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格 (while等待)
//把标点符号前面的空格删掉；//
//原文中所有大写英文字母变成小写，除了 I
//独立的 can you、could you 对应地换成 I can、I could——
//这里“独立”是指被空格或标点符号分隔开的单词；
//把原文中所有独立的 I 和 me 换成 you；
//在一行中输出替换后的句子作为 AI 的回答。
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
string s;
vector<char> ai_str;
string m[4][2] = {"can you", "* can", //*是为了防止将I can/could中的I错改为you
                  "could you", "* could",
                  "I", "you",
                  "me", "you"};
int cnt;
int main()
{
    cin >> cnt;
    getchar();
    while (cnt--)
    {
        getline(cin, s);
        cout << s << endl;
        while (s[0] == ' ')
            s.erase(s.begin()); //处理第一个
        while (s[s.length() - 1] == ' ')
            s.erase(s.end() - 1); //删除最后一个

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ') //删除连续空格
            {
                while (s[i + 1] == ' ')
                    s.erase(i + 1, 1);
                if (!isalnum(s[i + 1]))
                    s.erase(i, 1); //在有空格的情况下 为标点符号 删除上一个空格
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]) && s[i] != 'I') //除I外的大写字母转小写
            {
                s[i] += 32;
            }
            else if (s[i] == '?') //问号变感叹号
            {
                s[i] = '!';
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int index = s.find(m[i][0]);
            int l = m[i][0].length();
            while (index != -1)
            {
                if ((index == 0 || !isalnum(s[index - 1])) && (index + l == s.size() || !isalnum(s[index + l])))
                {
                    s.replace(index, l, m[i][1]); //从index下标开始将长度为l的子串替换为m[i][1]
                }
                index = s.find(m[i][0], index + 1); //从index+1开始找，找到第一个出现目标字符串的下标
            }
        }
        cout << "AI: ";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
                printf("I");
            else
            {
                printf("%c", s[i]);
            }
        }
        cout<<endl;
    }

    return 0;
}