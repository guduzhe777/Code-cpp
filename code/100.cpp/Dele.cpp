#include <iostream>
using namespace std;


int main()
{

    //输入n 产生  arr[n]  开始查找除去相同数字的长度
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    int i = 0,j = 1;
    
    // while(j<=n)
    // {
    //     if(arr[i] != arr[j])        //只要不等就增增
    // {
    //     ++i;
    //     ++j;
    // }
    // else{
    //     ++j;
        
    // }
    // }
    // cout << i <<endl;

    //分成两种情况   i j 都增加  /  只有 j增加 所以j不管怎么样 都会增加  所以用for循环
    //当相同的时候 j++
    //不同的时候  i j ++  且 ++i 值改变

    //j永远都会自增  
    //分成 相同  不同两种情况
    for(j = 1;j<n;j++)
    {
        if(arr[j] != arr[i])
        {
            arr[++i] = arr[j];
        }
    }
    cout << i + 1 <<endl;

    return 0;
}