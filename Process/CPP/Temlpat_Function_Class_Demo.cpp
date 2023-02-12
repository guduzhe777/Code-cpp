#include <bits/stdc++.h>

/**
 * @brief templat 在函数模板 类模板上的用法
 *
 *
 */
using namespace std;
// templat 约束一段{ } 结束
template <typename T> //作用于类
                      // 一天有类模板 走到哪里都要带着类模板 装一下b 让别人知道自己有类模板
class Fac
{
    //友元 可以 访问 类的 私人数据 private
    friend T operator+(Fac<float> f1, Fac<float> f2);
    friend void myprint(Fac<float> &f1);

private:
    T a, b;

public:
    T denominator, molecule;   // 一个类中可以有多个构造函数，只能有一个析构函数。
    Fac(T a, T b) : a(a), b(b) //构造函数形参和对象中的参数没有关系 若想赋值    //方法1 //构造函数的 给类中的 元素赋值
    {                          // fac(T a = 1,b = 1)  （直接赋值）指明 T为 int类型 //Fac<float> f1(1.1,2.1);（主函数声明类的时候）
        denominator = a;
        molecule = b;
        this->a = a;
        this->b = b;
    }
    T getmax()
    {
        return denominator > molecule ? denominator : molecule;
    }
    T min1(T, T);
};
//友元重载
//组成：	返回值 重载符号 (参数) MM operator+(MM a, MM b)
// template <typename T>
float operator+(Fac<float> a, Fac<float> b) //重载运算符？
{
    return a.a - b.a;
}
template <typename cc> //反正说明 我是背靠有类模板的类！
cc Fac<cc>::min1(cc a, cc b)
{
    return a < b ? a : b;
}
template <typename T>
T max1(T a, T b)
{
    return a > b ? a : b;
}
void myprint(Fac<float> &f1)
{
    cout << "f1 的私人数据 a,b" << f1.a << "  " << f1.b << endl;
}

int main()
{
    Fac<float> f1(10.1, 2.1); //类模板调用 必须标明 类的类型  //默认传给 构造函数！
    Fac<float> f2(22.1, 2.1);
    cout << f1.getmax() << endl;
    cout << max1(1.2, 2.3) << endl;
    cout << f1.min1(1.2, 2.3) << endl;
    myprint(f1);
    cout << f1 + f2 << endl;
    return 0;
}