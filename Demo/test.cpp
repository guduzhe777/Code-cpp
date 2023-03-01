//sort利用 取数组中变量直接比较
//getline(cin,str) getline 以一行为输入 到str中 
//string :不适合在结构体用
// （1）string是对象，不是一段内存，不适合放在结构体中。
// （2）只是在内存中用是可以用string的。
//     不能记录到文件里面，如果记录到文件里面，就会有问题。
// （3）string strTestString;
//     memset(&strTestString, 0, sizeof(string));//会报segment fault. 错误
//     string有一些变量，会保存string类的信息，如果使用memset，这些变量的值会被修改。从而导致string里的值被修改，如果这时  再对其赋值的话，可能像会对空指针赋值一样，导致非法访问错误。
//     对于string的对象是不能使用memset的，无论是单独使用还是放在结构体中。
//     所以，结构体中使用string一定要小心，最好使用char *，这样使用memset就不会出错。

#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N = 1010;

bool cmp_int(const int &a, const int &b)
{
    return a<b;
}

struct book{
    char name[110];
    double price;
};
book books[N];
bool cmp_book(const book &a,const book &b)
{
    return a.price<b.price;
}
int main()
{
    int arr[N];
    int n;
    cin>>n;
    //int 类型
    // for(int i = 1;i<=n;i++)
    // {
    //     cin>>arr[i];
    // }
    // sort(arr+1,arr+n+1,cmp_int);
    // for(int i = 1;i<=n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    //输入到结构体
    //以空格输入 %[^\n]
    for(int i = 1;i<=n;i++)
    {
        getchar();
        scanf("%[^\n] %lf",books[i].name,&books[i].price);

    }

    for(int i = 1;i<=n;i++)
    {
       printf("%s %lf",books[i].name,books[i].price);
    }

    
    return 0;
}