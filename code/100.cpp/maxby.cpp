#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    return a>b?a:b;
}
int cmp(const void *a,const void *b)
{
    return (*(int *)a) * (*(int *)b);
}
int maximumProduct(int* nums, int numsSize){
    
    
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    return max(nums[0]*nums[1]*nums[numsSize-1],nums[numsSize-3]*nums[numsSize-2]*nums[numsSize-1]);
    

}
// int cmp(int* a, int* b) {
//     return *a - *b;
// }

// int maximumProduct(int* nums, int numsSize) {
//     qsort(nums, numsSize, sizeof(int), cmp);
//     return fmax(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1]);
// }
int main()
{
    int arr[4] = {1,2,3,4};
    maximumProduct(arr,4);
    


    return 0;
}
