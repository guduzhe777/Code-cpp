#include <iostream>

using namespace std;

typedef int emdata;
class queue
{

    int Top, Tail; //队列 头部  尾部
    emdata *data;  //
    int n = 20;

public:
    queue()
    {
        Top = 0;
        Tail = 0;
        data = (emdata *)malloc(n * sizeof(emdata)); ///分配内存空间
    }
    //判断空   出队  入队
    //流出来最后一个  我们以后都是 指针先到位置再赋值
    int Isfull()
    {
        if ((Tail + 1) % n == Top) //当尾部和头部相邻
        {
            return 1;
        }
        return 0;
    }
    int Isempty()
    {
        if (Top == Tail) //重合为空
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //入队
    void push(emdata ele)
    {
        if (!Isfull())
        {
            
            data[Tail++] = ele;
            Tail = Tail%n;
        }
        else
        {
            cout << "Queue is full!" << endl;
        }
    }
    void print()
    {
        for (int sign = Top; sign != Tail; sign = (sign +1)%n)  //重合那么输出完了  重合处不输出
        {
            printf("%d ", data[sign]);
        }
    }
    emdata pop() //出队 返回 队列中的元素
    {
        if (!Isempty())
        {
            int ret = data[Top++];
            Top = Top % n;
            return ret;
        }
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int Len()
    {
        if (Tail == Top)
        {
            return 0;
        }
        return (Tail - Top + n) % n;
    }
};

int main()
{
    queue queue0;
    emdata ele;
    while (cin >> ele)
    {
        queue0.push(ele);
    }
    printf("Queue Len is %d ", queue0.Len());
    cout << endl;
    queue0.print();

    queue0.pop();
    cout << endl << "删除队头后：" << endl;

    queue0.print();

    return 0;
}