#include <iostream>
#include <cmath>

using namespace std;

//旋转二维 基于边界值多次循环输入  分别是i 不变 行输入  j不变列输入
class solution{
    public:
    int Rota2Dinput()
    {
        
        int n;
        cin >> n;
        int arr[n][n]; 
        int len = n;
        int startx = 0,starty = 0;//循环开始地
        int i = 0,j = 0; //用于指向//竖是x i  横是y j
        int loop = len / 2;//一共需要几次循环
        int num = 0;//用于放到数组中的值
        int offse = 0;//用于记录第几次循环 作用：每次循环后边界改变！！！
        
             
        while(loop--)
        {   //最后一个归下一个整体操作  我们不动他
            ++offse;
            for(j = starty;j<len-offse;j++) //x轴不变  y轴不断赋值 
            {
                arr[i][j] = ++num;
            }
            for(i = startx;i<len-offse;i++)
            {
                arr[i][j] = ++num;
            }
            for(;j>offse - 1;j--)
            {
                arr[i][j] = ++num;
            }
            for(;i>offse - 1;i--)
            {
                arr[i][j] = ++num;
            }
            startx++;//循环结束 开始下标也会改变
            starty++;
            
        }
        if(n%2 != 0)
            {
                arr[n/2][n/2] = n*n;
            }
   for(i = 0;i<n;i++)
   {
         for(j = 0;j<n;j++)
         {
            cout<<arr[i][j]<<endl;
         }
   }

    }
};
int main()
{
    solution s;
    s.Rota2Dinput();
    
   system("pause");
   return 0;
}
