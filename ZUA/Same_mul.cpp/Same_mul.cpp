#include <iostream>
#include <cmath>

using namespace std;
int max(int x,int y)
{
    return x>y?x:y;
}

//暴力：
void test0()
{
     int n,k,t;
   cin >> n;
   while(n--)
   {
        cin >> k >>t;
        for(int i = max(k,t);;i++)
        {
            if((i % k == 0)&&(i % t == 0))   //写一个在二者大的哪个 开始一直暴力增加
            {
                cout<<i <<endl;
                break;//退出循环
            }
        }
   }

}
int main()
{
    
  
    test0();    //暴力：
  
   return 0;
}
