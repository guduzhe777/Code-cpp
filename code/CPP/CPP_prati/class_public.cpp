#include<iostream>


using namespace std;




class	Box
{
	public:
		
		
		double g;
		Box();		//必须和类名相同
		~Box();
		
		
		
	double getvolume(void);	//在类中声明 外面才可以用  或者直接在类中写出函数 
								// 
//		{
//			return l * k * g;
//		}//	

	double getVolume(void)//类的里面写体积函数
	{
		return l * k * g;
	} 
	void setwid(int wid)	//设置 宽度 
	{
		k = wid;		
	}
	
	double getwid()			//返回宽度 
	{
		return k;			//直接类中的名称 引用 
	}
	void set_lon(double lon)//设置长
	{
		l = lon;
	}
	double get_lon()	//返回长
	{
		return l;
	}
	private://宽放到私人	//只能在内部访问 如果外部需要用  可以在内部返回
	double k; //实际的宽度储存 



	protected://长放到保护	//相似私有成员(外部无法访问)，但有一点不同，
	double	l;	//保护成员在派生类（即子类）中是可访问的。
	
	 
	
} ;
//设置子类 然后用到父类的数据l 
//子类长和父类一样 get 父类 长
class SmallBox:Box		//注： 父子类 数据在不同空间  跳出父类 父类数据就被重置？
{
	public:
	double get_lon()////子类返回长
	{
		return l;
	}
	void set_lon(double lon)////子类设置长
	{
		l = lon;
	}
};
	

double Box ::getvolume(void)		//类的外面 返回类型 + 在哪个类名字的 Box::表示 
{
	return l * k * g;
}
Box::Box(void)	//
	{
		cout <<"Init fun"<<endl;
	}
Box::~Box(void)
	{
		cout <<"init fun dele"<<endl;
	}


int main()
{
	int a,b,c;
	Box Box1;
	cin >> a >> b >>Box1.g ;
	SmallBox SmallBox1;
	Box1.setwid(a);	//输入宽度 
	Box1.set_lon(b);//输入长度
	cout <<"宽："<< Box1.getwid ()<<"体积： " << Box1.getvolume() <<" 子类求的长：" <<SmallBox1.get_lon()<<endl;	//显示宽度 
	// 	1 2 3
// // 宽：1体积： 6 子类求的长：0
// 	cout <<" 父类求的长：" <<Box1.get_lon()<<endl;
// 	//  父类求的长：2
// 	SmallBox1.get_lon();	//
// 	cout <<" 子类修改后父类求的长：" <<Box1.get_lon()<<endl;
// //  子类修改后父类求的长：2
// 	cout <<" 子类修改后子类求的长：" <<SmallBox1.get_lon()<<endl;
// //  子类修改后子类求的长：10

// //足以说明 虽然子类用的父类 但是数据是不相关的
// //子类不能用父类的函数 因为不匹配  但是可以用数据
// //


	return 0;
}
