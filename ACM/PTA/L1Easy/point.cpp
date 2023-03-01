#include<bits/stdc++.h>
#include<string>
using namespace std;

const int N = 1010;
struct book{
	string name;
	int price;
};
book books[N];

bool cmp( book* a, book* b)
{
	return a->price < b->price;
}

int main()
{
	int n;
	cin>>n;

	book **ptrls = new book[n];

	for(int i = 0;i<n;i++)
		cin >> ptrls[i].name
	for(int i = 0;i<n;i++)
	{
		cin>>books[i].name>>books[i].price;
	}
	for (int i = 0; i < n; i++)
	{
		ptrls[i]=&books[i];
	}
	
	sort(ptrls,ptrls+n,cmp);
	for(int i = 0;i<n;i++)
	{
		cout<<ptrls[i]->name<<" "<<ptrls[i]->price<<endl;;
	}
	//不改变原数组 通过指针指向位置不同而明确 price高低
	return 0;
}
