#include <bits/stdc++.h>
#include <vector>

using namespace std;

using PII = pair<int,int>;

//方案对应是否对矩阵操作   编号对应矩阵
// change 保存 如何对矩阵的行列 同时修改
const int N = 5;
int change[N][N];
string f; //保存字符串 等待处理

//1<<get(i,k);
int get(int i, int j)
{
    return i * 4 + j;
}
int main()
{

    int state = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> f;
        for (int j = 0; j < 4; j++)
        {
            if (f[j] == '+') // 1 + 代表锁着
            {
                state += 1 << get(i, j); //将状态放到数字中！
            }
        }
    }
    int now = state;
    //得到矩阵的数字形态
    //得到如何修改行列
    // k代表方案数 这里不动了先 等会把所有方案数全部放上
    //修改行列？
    //得到修改行列数组
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for(int k = 0;k<4;k++)
            {
                change[i][j] += 1<<get(i,k);//对行
                change[i][j] += 1<<get(k,j);//对列 保存
            }
            //1<<get(i,k); 把1 放在固定编号上 等待被异或
            change[i][j] -= 1<<get(i,j);//减去重复 这便是 change的改变行列的关键
        }
    }
    //change 已经就绪
    // for(int k = 0;k<16;k++)
    // {

    // }
    
    vector<PII> res;
    vector<PII> pair;
    for(int k = 0;k< 1<<16 ; k++) //对应16位的修改情况 
    {
        //最初情况相同 所以
        
        now = state;
        for(int i = 0;i<16;i++)//如果编号i被修改 编号i和移位i 相同
        {
            if(k>>i&1)
            {
                int a = i/4;
                int b = i % 4;
                now ^= change[a][b];
                pair.push_back({a,b});
            }
        }
        if((!now)&&(res.empty()||res.size()>pair.size()))//如果 变完之后全为0！ 且 要么 结果为0（第一次）/ 比较res pair步骤 
        {
            res = pair;
        }
        //这次比较完毕  下次选择新的状态 用pair 应该为空
        pair.clear();  
    }
    cout<<res.size()<<endl;
    
    //修改方案穷举完毕 
     for (auto &p : res)
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    return 0;
}