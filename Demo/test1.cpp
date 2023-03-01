//sort利用 取数组中变量直接比较
//getline(cin,str) getline 以一行为输入 到str中 
//
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
    for(int i = 1;i<=n;i++)
    {
        getchar();
        scanf("%[^\n] %lf",books[i].name,&books[i].price);
    }
    sort(books+1,books+n+1,cmp_book);
    for(int i = 1;i<=n;i++)
    {
        printf("%s %lf\n",books[i].name,books[i].price);
    }

    cout<<"highest price: "<<books[n].price<<","<<books[n].name<<endl;
    cout<<"lowest  price: "<<books[1].price<<","<<books[1].name<<endl;
    
    return 0;
}