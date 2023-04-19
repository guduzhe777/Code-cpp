#include <bits/stdc++.h>

using namespace std;

int n, m, k;

queue<int> machion;
const int N = 1e3 + 10;
int tree[N], tree_pos;
stack<int> box;

//限制条件 立马判断
//尽管逻辑正确  更应该理解后 更换主体是否有更好的 解法  这个主题为盒子空不空 =>> 松片是否用完
//限制条件：松枝是否插满 ； 盒子是否容量满；，我们 在 插入新元素后 可以思考 立马判断 也可以 在插入之前立马判断 
//but  不能离太远。
//具有容器思想：插入元素 意思是：可以放在哪里？
//
int main()
{

    cin >> n >> m >> k; //松片数   盒子容量  松枝承载容量
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        machion.push(x);
    }

    // n >> m >> k;//松片数   盒子容量  松枝承载容量
    while (machion.size() || box.size())
    {
        if (!tree_pos)
        {
            if (box.size())
            {
                tree[++tree_pos] = box.top();
                box.pop();
            }
            else
            {
                tree[++tree_pos] = machion.front();
                machion.pop();
            }
        }
        else
        { //不空   //松枝不空。  //一次添加一个  然后 立马判断 是否 满  立刻 判断。 
            //若 不空 则 立马 判断是否超过松枝容量

            //对应一次只添加一个

            if (tree_pos == k )//首先判断 松枝是否满   //保证了以后可以添加
            {
                bool fir = true;
                for (int i = 1; i <=tree_pos; i++)
                {
                    if (fir)
                    {
                        fir = false;
                        printf("%d", tree[i]);
                    }
                    else
                    {
                        printf(" %d", tree[i]);
                    }
                }
                tree_pos = 0;
                printf("\n");
                continue;
            }
            if (box.size() && box.top() <= tree[tree_pos])
            {
                tree[++tree_pos] = box.top();
                box.pop();
            }
            else if (machion.size() &&machion.front() <= tree[tree_pos])
            {
                tree[++tree_pos] = machion.front();
                machion.pop();
            }
            else if (box.size() < m && machion.size()) //能 放到盒子中 
            {
                box.push(machion.front());
                machion.pop();
            } else  if(machion.empty() || box.size() == m) //当实在放不进去 即：box 满了 box machion 第一个都放不进去  || 机器空了 box  第一个放不进去 
            {
                bool fir = true;
                for (int i = 1; i <=tree_pos; i++)
                {
                    if (fir)
                    {
                        fir = false;
                        printf("%d", tree[i]);
                    }
                    else
                    {
                        printf(" %d", tree[i]);
                    }
                }
                tree_pos = 0;
                printf("\n");
            } 
            
            
        }
    }
    bool fir = true;
    for (int i = 1; i <= tree_pos; i++)
    {
        if (fir)
        {
            fir = false;
            printf("%d", tree[i]);
        }
        else
        {
            printf(" %d", tree[i]);
        }

    }
    
    return 0;
}