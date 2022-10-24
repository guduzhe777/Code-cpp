#include<iostream>
//#define maxsize 100;    //C++中，类的成员中不能有宏定义。
//#define n 80;           
using namespace std;
typedef int emdata;
class stack{    //不做特别说明，类的数据成员和成员函数都被认为是private
    //1.
    // int top;//栈顶部
    // int arr[100];//栈空间

    //2.
    private:
        emdata *data;
        emdata maxsize;
        emdata ret;
               //始终指向有元素的哪一个
        int n = 20;     //扩容空间
        //初始化   //用指针访问空间 初始化栈顶
        //入栈
        //出栈
        void init_stack()//初始化 栈顶 内存空间
        {   
            top = -1;
            data = (emdata*)malloc(maxsize * sizeof(emdata));
        }
    public:
        int top; 
        stack(){
            maxsize = 10;   //设置最大栈空间
            init_stack();   //初始化
        }   
        int push(emdata x)//传入元素
        {
            if(top >= maxsize - 1)   //满了（top始终指向最上面存有元素的空间）
            {
                data = (int*)realloc(data,n);
            }
            data[++top] = x;
            return 1;

        }
        emdata pop()    //返回出栈值
        {
            if(top != -1)
            {
                ret = data[top--];  //返回值
                return ret;
            }
            return -1;
        }
};


int main()
{
    stack a;
    int x,n,reMain,ret;//输入数字  需要的进制
    cin >> x>>n;//输入数字  需要的进制
    while(x / n)
    {
        reMain = x%n;
        a.push(reMain);
        x /= n;
    }
    a.push(x%n);

    
       
    while(a.top != -1)
    {
        ret = a.pop();
        
        if(n==16){//若为16进制 
			if(ret==10)
				printf("A");
			else if(ret==11)
				printf("B");
			else if(ret==12)
				printf("C");
			else if(ret==13)
				printf("D");
			else if(ret==14)
				printf("E");
			else if(ret==15)
				printf("F");
			else printf("%d",ret);						
		}
		else
			printf("%d",ret);//2进制和8进制 

    }   
   
    
    return 0;
}