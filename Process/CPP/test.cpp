#include <iostream>
#include <string>
using namespace std;
class MM
{
public:
	MM() {}
	MM(string name, int score) :name(name), score(score) {}
	void print()
	{
		cout << name << "\t" << score << endl;
	}
	//友元重载
	friend MM operator+(MM a, MM b);		//加法重载函数的声明
protected:
	string name;
	int score;
};
MM operator+(MM a, MM b)
{
	return MM(a.name+b.name, a.score + b.score);  //返回一个匿名对象
}
int main()
{
	int a = 1;//基本数据类型运算符直接用
	int b = 2;
	int sum = a + b;
	MM mm("小芳", 6);
	MM girl("芳", 2);
	//error: 没有与这些操作数匹配 "xxx" 运算符
	//重载函数的隐式调用 -->mm + girl 解析为:operator+(mm, girl)
	MM result = mm + girl;				  
	result.print();
	//重载函数显示调用：按照函数的调用方式
	MM res = operator+(mm, girl);		  //operator+:函数名  参数 
	return 0;
}