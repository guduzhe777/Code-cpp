#include<iostream>
using namespace std;
/*求三个数最大值*/
int max3(int i, int j, int k)
{
    if (i>=j && i>=k)
        return i;
    return max3(j, k, i);
} 
int maxsequence2(int a[], int l, int u)
{
    if (l > u) return 0;
    if (l == u) return a[l];
    int m = (l + u) / 2;
 
    /*求横跨左右的最大连续子序列左半部分*/   
    int lmax=a[m], lsum=0;
    for (int i=m; i>=l; i--) {
        lsum += a[i];
        if (lsum > lmax)
            lmax = lsum;
    }
    
    /*求横跨左右的最大连续子序列右半部分*/   
    int rmax=a[m+1], rsum = 0; 
    for (int i=m+1; i<=u; i++) { 
        rsum += a[i];
        if (rsum > rmax) 
            rmax = rsum; 
    }
    return max3(lmax+rmax, maxsequence2(a, l, m), maxsequence2(a, m+1, u)); //返回三者最大值
}
 

int main()
{
    int arr[101],n;
    cin >>n;
    for(int i = 0;i<n;i++)
    {
        cin >>arr[i];
    }
    //int ret1 = cacl1(arr,n);
    int ret2 = maxsequence2(arr,0,n-1);
   // int ret3 = cacl3(arr,n-1);
    //cout <<ret1 <<endl;
   cout << ret2 <<endl;

    return 0;
}