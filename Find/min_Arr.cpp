#include <iostream>
#include <cmath>

using namespace std;
class solution{
    public:
    //寻找 大于tss的 数列最小长度
    //遍历数组  如果大于  长度记录 然后比较 
        int min_ArrA(int arr[],int target,int len)
        {
            //暴力： 全部情况都囊括进去了 不管你大小数组
            //i计次+选择开始 j开始选择
            int min_len = -1,min_rec = -1,sum = 0;
            for(int i = 0;i<len;i++)
            {
                sum = 0;//重复用到的数据需要更新 因为每次开头不一样
                for(int j = i;j<len;j++)
                {
                    sum += arr[j];
                    if(sum >= target)
                    {
                        min_rec = j - i + 1;
                        //如果记录小于最小替换
                        if(min_rec<min_len)
                        {
                            min_len = min_rec;
                        }
                    }
                }
            }
            return min_len;
        }
        //目的不断减减 试探底线 得到最短长度 尾部指针决定 我们可以访问到任何子序列 基于关系
        int min_ArrB(int arr[],int target,int len)
        {
            int min_rec = -1,min_len = 100000,sum = 0,i = 0,j = len-1;
            for(j = 0;j<len;j++)
            {
                //加上值
                sum += arr[j];
                //每次值大于target试探底线   
                while(sum>=target)
                {
                    min_rec = (j-i+1);//获取试探后长度 
                    min_len = min_rec<min_len?min_rec:min_len;//更新长度
                    sum -= arr[i++];//试探底线
                }
            }
            //从后向前 这是一个加了之后 不断减试探底线 且记录最短 的过程
            // for(i = len - 1;i>=0;i--)
            // {
            //     sum += arr[i];
            //     while(sum >=target)
            //     {
            //         min_rec = (j - i + 1);
            //         min_len = min_rec<min_len?min_rec:min_len;
            //         sum -= arr[j--];
            //     }
            // }
            return min_len;
        }
};
int main()
{
    solution s;
    int arr[101],n,target;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cin>>target;
    int ret = s.min_ArrB(arr,target,n);
    cout <<ret<<endl;
    system("pause");
    return 0;
}
