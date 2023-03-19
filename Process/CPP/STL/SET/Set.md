**set **

set 翻译为集合，是一个内部自动有序且不含重复元素的容器。

**去重  且 内部有序**

只能通过迭代器去访问 

*it

~~~
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        printf("%d ", *it);
    }
    return 0;
}
~~~

