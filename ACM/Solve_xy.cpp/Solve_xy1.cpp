#include <iostream>

using namespace std;

class solution
{
public:
    //利用欧几里得 求解二元一次方程
    //递归到最后一层  得到x y  返回 求上一层的x y
    //int temp = y;
    //   y = x - (a/b) * b * y;      //这一层的y 
    //   x = temp;
    int Euclidexpand(int a,int b,int &x,int &y) // 引用 可以改变值
    {
        if(b == 0)
        {
            x = 1;  //等式可以直到
            y = 0;  //y根据等式可以随便取  取0好计算
            return a;   //最大公约数
        }
        int r = Euclidexpand(b,a%b,x,y);    //一直向下求 
        int temp = y;
        y = x - (a/b) * y;      //这一层的y  利用等式 + 上一层的x y
        x = temp;           //这一层的x;     利用等式 + 上一层的x y
        return r;//把最大公约数返回 
    }
    //最后得到最终x y
};

int main()
{
    solution s;
    int a,b,x,y;
    cin>>a>>b;
    s.Euclidexpand(a,b,x,y);
    cout<<s.Euclidexpand(a,b,x,y)<<"   "<<" x y 值为："<< x<<"  "<< y<<endl;
    return 0;
}