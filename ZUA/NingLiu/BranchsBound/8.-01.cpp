#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TempStg //创建T类型的数据对象，并负责清理这些对象，防止内存泄漏 
{
	private:
		struct node
		{
			T *dat;
			node *next;
		};
		node H; //头结点不存数据
	public:
		TempStg()
		{
			H.next=0;
		}
		~TempStg()
		{
			node *p=H.next;
			while(p)
			{
				node *t=p;
				p=p->next;
				delete t->dat;
				delete t;
			}
		} 
		T *newNode() //添加元素
		{
			node *q=new node;
			q->dat=new T; //产生新数据空间
			q->next=H.next;
			H.next=q;
			return q->dat;
		}
};
template <typename T>
class minHeap //小顶堆
{
	private:
		T d[1000]; //堆空间，最多容纳1000个元素
		int tail; //尾元素下标
		void dsort(int t) //堆排序
		{
			int L=t*2+1,R=t*2+2;
			if(L<=tail)
			{
				dsort(L);
				if(d[t]->value()>d[L]->value()) swap(d[t],d[L]);
			}
			if(R<=tail)
			{
				dsort(R);
				if(d[t]->value()>d[R]->value()) swap(d[t],d[R]);
			}
		}
	public:
		minHeap():tail(-1){}
		void Add(T dat) //向尾部添加元素
		{
			d[++tail]=dat;
			dsort(0);
		}
		void Delete(T &e) //弹出队头元素，没有考虑队列已空的情况
		{
			e=d[0];
			swap(d[0],d[tail--]);
			dsort(0);
		}
		bool IsEmpty() //判空
		{
			return tail==-1;
		}
};

struct task{
    int cCost; //当前花费
    int level;  //当前层次
};

int n;
int bestCost = INT_MAX;
int temCost = 0;
vector<vector<int> > cost_Matrix;
vector<int> s;
vector<int> minCosts;
int bound(int i)
{

}
int down(int i)//获取 i - 目标下界
{
    for(int j = i;j<=n;j++)
    {
        
    }
}
void taskAssignment()
{
    
     
    int i = 1;
    int wt = 0;
    minHeap<task> a;
    TempStg<task> temp; // 用于动态分配内存
    while(i != n + 1)
    {
        
        for(int j = 1;j<=n;j++)
        {
            int cCost = cost_Matrix[i][j];
            down = 
        }

    }


}
int main()
{
    cin>>n;
    cost_Matrix.resize(n+1,vector<int>(n+1,0));
    s.resize(n+1,0);
    minCosts.resize(n+1,0);
    
    for(int i = 1;i<=n;i++)
    {
        int x = INT_MAX;
        for(int j = 1;j<=n;j++)
        {
            cin>>cost_Matrix[i][j];
            x = x<=cost_Matrix[i][j]?x:cost_Matrix[i][j];
        }
        minCosts.push_back(x);
        temCost += x;
    }
    taskAssignment();

    return 0;
}