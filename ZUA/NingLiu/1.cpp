#include <iostream>
#include<bits/stdc++.h>

using namespace std;

template<class Type>
// i ： 第i个元素在 k -  i-1 是否有重复
int sift(Type a[],int k,int i)
{    /////////////
    //提示：用来判断a[i]与其前面的元素有没有相同值
     ///////////
     if(i>k)
     {
          for(int j = k;j<i;j++)
          {
               if(a[i] == a[j]) return 0;
          }
     }
     return 1;
}

template<class Type>
void ranks(Type a[],int k,int m)
{    
     if(k == m)
     {
          for(int i = 0;i<=m;i++)
          {
               cout<<a[i]<<" ";
          }
          cout<<"\n";
     }
     for(int i = k;i<=m;i++)
     {
          if(sift(a,k,i))
          {
               swap(a[k],a[i]);
               ranks(a,k+1,m);
               swap(a[k],a[i]);
          }
     }
}

template<class Type>
inline void swap(Type &a,Type &b)
{	Type temp=a;a=b;b=temp;
}
int main()
{	char a[3]={'a','b','b'};
	ranks(a,0,2);
	return 0;
}

