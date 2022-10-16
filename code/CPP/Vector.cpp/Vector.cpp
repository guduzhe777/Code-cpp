#include<vector>
#include<iostream>


using namespace std;


void test()
{
    // vector<int> v2;
    //关于基本命令
    // v2.push_back(1);
    // v2.push_back(2);
    // v2.push_back(3);
    // v2.push_back(4);
    // v2.capacity();
    // vector<int>::iterator it = v2.begin();
    // // for(;it!=v2.end();it++)
    // // {
    // //     printf("地址：%d 值%d",it,*it);
    // // }
    // //地址：1382688 值1地址：1382692 值2地址：1382696 值3地址：1382700 值4
    // //足以说明连续空间
    // // cout<<endl;

    //关于开辟空间 
    // vector<int>::iterator it = v2.begin();
    // int cnt = 0; 
    // cout <<"第 "<<cnt <<" 次"<<"  容量为："<<v2.capacity()<<"  元素个数:  "<< v2.size()<<endl;
    // for(int i = 0;i<100;i++)
    // {
    //     v2.push_back(i);
        
    //     if(it != v2.begin())
    //     {
    //         cnt++;
    //         cout <<"第 "<<cnt <<" 次"<<"  容量为："<<v2.capacity()<<"  元素个数:  "<< v2.size()<<endl;
    //         it = v2.begin();
    //     }
    // }
    vector<int>v1(3,100);
    printf("预留前：v1的容量%d 大小：%d\n",v1.capacity(),v1.size());
    v1.reserve(1000);
    vector<int>v2(3,101);
    vector<int>v3(3,102);
    
    //容器嵌套
    // vector<vector<int>>vv;   //一层一个尖角  所以两次就到了int
    // vv.push_back(v2);
    // vv.push_back(v2);
    // vv.push_back(v3);
    // vector<vector<int>>::iterator it ; //每个容器都有自己的迭代器 迭代器指向元素 类似指针！用它需要解引用* *it就是v2
    // for(it = vv.begin();it != vv.end();it++) 
    // {
    //     vector<int>::iterator mit;
    //     for(mit = (*it).begin();mit != (*it).end();mit++)
    //     {
    //         cout << (*mit) <<"  ";
    //     }
    //     cout <<endl;
    // }

    //swap的巧妙缩小不需要空间
    vector<int>v4(2,100);
    v4.reserve(4);
    printf("v4的容量%d 大小：%d\n",v4.capacity(),v4.size());
    printf("v1的容量%d 大小：%d\n",v1.capacity(),v1.size());
    v4.swap(v1);//一般全部交换 容量也会交换  匿名对象不会
    
    printf("v1的容量%d 大小：%d\n",v1.capacity(),v1.size());
    printf("v4的容量%d 大小：%d\n",v4.capacity(),v4.size());
    vector<int>(v1).swap(v1); 
    printf("v1的容量%d 大小：%d\n",v1.capacity(),v1.size());
}

int main()
{

    test();
    return 0;
}