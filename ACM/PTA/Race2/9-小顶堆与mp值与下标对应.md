**堆维护数组/vector**

~~~c++
vector<int> v;
push_heap(v.begin(),v.end(), greater<int>);

~~~

**查找堆中元素 直接查找为o(n)**

~~~c++
int x;
cin>>x;
for(int i = 0;i<n;i++)
{
	if(x == v[i])//o(n) 查找 
	{
		
	}
}
~~~

**map映射----查找数组中元素下标。(元素不重复)**

~~~
map<int,int> mp;//数值 下标

mp[heap[i]] = i + 1;//下标标记 直接/2 为父亲  父亲 还是 父亲 孩子还是孩子 不过 标记改变

//查找元素下标
if(mp[3] / 2 == mp[5] / 2) 。//同一个父亲
~~~

**堆维护**

~~~c++
push_heap(v.begin() + 1,v.end(),greater<int>() );//每次添加一个元素即要维护一次 数组/vector/堆
~~~

