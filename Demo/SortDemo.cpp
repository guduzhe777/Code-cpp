// sort利用 取数组中变量直接比较
//利用指针指向 元素 对指针排序
// getline(cin,str) getline 以一行为输入 到str中
//
#include <bits/stdc++.h>
#include <string>
using namespace std;
const int N = 1010;

bool cmp_int(const int &a, const int &b)
{
    return a < b;
}

struct book
{
    char name[110];
    double price;
};
book books[N];
book* bookptr[N];
//对数组元素排序
bool cmp_book(const book &a, const book &b)
{
    return a.price < b.price;
}
//对指向数组元素的指针 进行排序 而不改变 元素位置
bool cmp_bookptr(const void* a,const void* b)
{
    return ((book*)a)->price<((book*)b)->price;
}
int main()
{
    
    int n;
    cin >> n;
    char ch;
    while ((ch = getchar() == ' '));
        
    // int 类型
    //  for(int i = 1;i<=n;i++)
    //  {
    //      cin>>arr[i];
    //  }

    // sort(arr+1,arr+n+1,cmp_int);
    // for(int i = 1;i<=n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    for (int i = 1; i <= n; i++)
    {
        getchar();
        scanf("%[^\n]", books[i].name);
        scanf("%lf", &books[i].price);
        bookptr[i] = &books[i];
    }
    //对数组元素排序
    // sort(books + 1, books + n + 1, cmp_book);
    
    
    // printf("highest price: %.1f, %s\n",  books[n].price,books[n].name);

    // printf("lowest price: %.1f, %s\n",books[1].price, books[1].name);

    //对指针排序

    sort(bookptr+1,bookptr+n+1,cmp_bookptr);//这里需要加一 c++一般都是左闭右开
    printf("highest price: %.1f, %s\n",  bookptr[n]->price,bookptr[n]->name);

    printf("lowest price: %.1f, %s\n",bookptr[1]->price, bookptr[1]->name);
    return 0;
}