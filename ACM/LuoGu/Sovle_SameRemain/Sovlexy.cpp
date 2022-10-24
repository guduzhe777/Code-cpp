#include<iostream>


using namespace std;

int x,y;
class solution{




public:
    int solvex_y(int a,int b)
    {
        if(b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        int r = solvex_y(b,a%b);
        int temp = y;
        y = x - (a/b) * y;
        x = temp;
        return r;
    }
};

int main()
{
    int a,b;
    cin >>a>>b;
    solution s;
    s.solvex_y(a,b);
    //得到一个解法 x = -3  y = 1  
    // while(x<0)
    // {
    //     x +=b;
    // }
    x = x%b;//加减单位个b 都在这条直线上 基于向量关系
    cout << x <<y <<endl;
    return 0;
}