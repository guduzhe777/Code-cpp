#include<iostream>

using namespace std;




int main()
{

    //通过指针设置动态数组 
    //realloc函数和上面两个有本质的区别，其原型void realloc(void *ptr, size_t new_Size) 返回空间地址
    //ptr为指向原来空间基址的指针，
    // new_size为接下来需要扩充容量的大小。
    //注：一般会直接在后面分配内存  but 多了之后 会找块新内存值也会复制过去  
    //but 你若是插入 可以直接全部后移！
    //realloc 重新分配空间（可以增加减小）  会改变内存中的值（） 
    //malloc(n*sizeof(int))  帮你分配n * int个 字节 返回空间地址
    //calloc(n,int):帮你分配 n个 int 类型 且初始化  返回空间地址
    
    int num,target,sign;
    cout << "输入初始元素个数 每个元素" << endl;
    cin >> num;
    int *parr = (int *)calloc(num,sizeof(int));
    
    for(int i =0;i<num;i++)
    {
        cin >> parr[i];
    }
     for(int i =0;i<num;i++)
    {
        cout << parr[i] <<endl;
    }
    cout << "输入插入 下标 及 插入的数字" << endl;
    cin >> sign >> target;
    int *parr1 = (int *)calloc(num,sizeof(int));
    //保存 
     for(int i =0;i<num;i++)
    {
        parr1[i] = parr[i];
    }
    //重置 
    parr = (int *)realloc(parr,(++num) * sizeof(int));
    //插入
    for(int i =0,j = 0;i<num;i++,j++)   //i 对应 parr  j  parr1
    {
        if(i == sign - 1)
        {
            parr[i] = target;  
            i++;
        } 
        parr[i] = parr1[j];       
    }
    cout << "插入后：" <<endl;
     for(int i =0;i<num;i++)
    {
        cout << parr[i] <<endl;
    }
    return 0;
}