#include<iostream>



using namespace std;
class solution{
    public://两类二分查找
           //边界问题
           //（类1：r为数组边界[l,r]）有序 不重复 从小到大：大于右脚下标mid-1  直到下标左等于右 
           //(类2：r为数组大小所以[l,r))
        int towFind(int arr[],int l,int len,int target)
        {
            // int r = len-1;
            //int mid = (l+r) /2;
            // while(l<=r)
            // {
            //     if(arr[mid]<target)
            //     {
            //         l = mid + 1; 
            //         mid =  (l + r)/2;
            //     }
            //     else if(arr[mid]>target){
            //         r = mid - 1;
            //         mid = (r + l)/2;
            //     }
            //     else {
            //         return mid;
            //     }
            // }
            int r = len;
            while(l<r)
            {
                int mid = (r-l) /2 + l; //防止溢出
                if(arr[mid] > target)
                {
                    r = mid;    //r不会被访问
                }
                else if(arr[mid]<target){
                    l = mid + 1;//l会被访问到
                }
                else {

                    return mid;
                }
            }
            return -1;
        }
};

int main()
{
    int arr[101],n,target;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin >>target;
    solution s;
    int ret = s.towFind(arr,0,n,target);
    cout <<ret<<endl;
    return 0;
}