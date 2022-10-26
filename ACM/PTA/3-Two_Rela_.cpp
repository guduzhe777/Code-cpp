#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
vvi relation;
int main()
{
    int N, M, K,sign = 0;
    cin >> N >> M >> K;                  //人数 每一对关系  查询
    relation = vvi(N + 1, vi(N + 1, 0)); //默认没关系 0 行 的 0列的不用了
    while (M--)
    {
        int b1, b2, r;
        cin >> b1 >> b2 >> r;
        relation[b1][b2] = r; //关系
        relation[b2][b1] = r;//关系是相互的
    }
    while (K--)
    {
        sign = 0;//默认在二者敌对 没有 共同朋友了
        int b1, b2;
        cin >> b1 >> b2;
        if (relation[b1][b2] == 1)
        {
            cout << "No problem"
                 << endl;
        }
        else if (relation[b1][b2] == 0)
        {
            cout << "OK"
                 << endl;
        }
        else if (relation[b1][b2] == -1)
        {
            for (int k = 1; k <= N;k++)
            {
                if((relation[b1][k] == 1)&&(relation[b2][k] == 1))
                {
                  cout << "OK but..."
                 << endl;
                  sign = 1;
                  break;
                }
            }  
            if(!sign)
            {
                cout << "No way"
                 << endl;
            }
        }
        
    }
    return 0;
}
