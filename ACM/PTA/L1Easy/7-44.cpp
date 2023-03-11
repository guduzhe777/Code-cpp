#include <bits/stdc++.h>

using namespace std;
// pair数组保存 符号与 对应字符
//判断是符号还是 字符 用第一个即可
//输入 一行 以 string保存 若不是 空格   str += str1[i] 若是竖线 输出空格
//去对应输出
//
typedef pair<char, string> PCS;
PCS order[40] = {{'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}};
int n;
string str;
void mscmcl(string str)
{
    string strtem;
    int sz = str.length();
    for (int i = 0; i < sz; i++)
    {
        strtem.clear();//开始情况 需要比较的
        while (str[i] != ' ' && str[i] != '|'&&str[i] != '\0')
            strtem += str[i++];
        for (int j = 0; j < 36; j++)
        {
            if (order[j].second == strtem)
            {
                cout << order[j].first; //输出对应
                break;
            }
        }
        if(str[i] == '|') cout<<" ";
        // if(str[i] == '\0')
        // {
        //      cout<<endl;
        //      return;
        // }
    }
    cout<<endl;//全部转化完
}
void chcl(string str)
{
    
    int sz = str.length();
    for(int i = 0;i<sz;i++)//处理这段字符
    {
        if(str[i] != ' '&&str[i] != '|')//不为 空格 | 那么字符
        {
            for(int j = 0;j<36;j++)//在pair里面寻找 对应的字符
            {
                if(order[j].first == str[i])
                {
                    if(i == 0||str[i-1] == ' ')  cout<<order[j].second;
                    else{
                        cout<<" "<<order[j].second;
                    }
                }
            }
        }
        if(str[i] == ' ') cout<<"|";//如果是空格 输出竖线

    }
    cout<<endl;//全部转化完
}
int main()
{
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, str);
        
        if (str[0] == '-' || str[0] == '.') //莫斯科码
        {
            mscmcl(str);
        }
        else
        { //字符
            chcl(str);
        }
    }
    return 0;
}