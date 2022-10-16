#include <iostream>
using namespace std;


int test0(int arr[],int len)
{
    ///总和sum    求和total   sum - curr == total (total 未加 curr 还) 
    //或者说sum（包含curr） == total （包含curr）  那么 找到中心
    int sum = 0,total = 0;
    for(int i = 0;i<len;i++)
    {
        sum += arr[i];      
    }
    for(int i = 0;i<len;i++)
    {
        total += arr[i];        //这6行保证了  arr[i] 在sum中 也在total 中
        if(total == sum)
        {
            return i;
        }
        sum -= arr[i];
    }
    return -1;
}
int test1(int arr[],int len)
{
    //2 * sum + curr == total （总和）
    int sum = 0,curr,total = 0;
    for(int i = 0;i<len;i++)
    {
        total += arr[i];

    }
    

}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    int sz = sizeof(arr) / sizeof(arr[0]);
    //int cent_sign = test0(arr,sz);
    int cent_sign = test1(arr,sz);
    cout << cent_sign <<endl;

    return 0;
}