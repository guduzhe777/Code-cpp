#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<string, int> PIS;
struct cmp1
{
    bool operator()(PIS &a, PIS &b)
    {
        //return less<int>()(a.second, b.second);
        return a.second > b.second;//
        //true 为交换 a 大于 b 则 交换 所以为升序
        //pair 早已 重载运算符< 
        //pair p1[n] sort(p1,pi+n) < 第一个 再 第二个
    }
};
// cmp1当作 比较优先级的 函数

// cmp1(a b) a<b a的优先级值小于b a优先级大于b

priority_queue<PIS, vector<PIS>, cmp1> pri_q;

int main()
{
    cin >> n;
    while (n--)
    {
        string s1;
        cin >> s1;
        if (s1 == "PUT")
        {
            string s2;
            int clas;
            cin >> s2 >> clas;
            pri_q.push({s2, clas});
        }
        else
        {
            if (pri_q.empty())
            {
                printf("EMPTY QUEUE!\n");
            }
            else
            {
                PIS this0 = pri_q.top();
                pri_q.pop();
                cout << this0.first << "\n";
            }
        }
    }

    return 0;
}