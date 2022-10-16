#include<iostream>
#include<vector>//由于vector是标准库中的类，在使用vector的时候我们需要包含标准库的头文件 < vector > .
                //vector 是容器  起了一个修饰作用 主类型还是int 这类


using namespace std;




int main()
{
    //vector<int> a(10);
    
    vector<int> a(10,1);
    vector<int> b(a.begin(),a.begin()+3);
    //a总归还是数组
    for(int i = 0;i<3;i++)
    {
        cout << a[i+1] <<endl;
    }  
    



    return 0;
}