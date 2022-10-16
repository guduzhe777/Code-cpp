/*
 * @lc app=leetcode.cn id=628 lang=c
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
// @lc code=start
//三个负数 -3 -2 -1 1 2 3
//三个正数  1 2 3 4 5 6
//有正有负  -3 -2 1 2 3 6
//          -3 1 2 3
//无非两种情况  最后三个 或者 前两个抵消负号 * 最大值 比较一下
//我们没有办法一步得到答案 需要结合情况分类讨论
int max(int a, int b)
{
    return a>b?a:b;
}
int maximumProduct(int* nums, int numsSize){
    int sz = sizeof(nums) / sizeof(nums[0]);
    return max(nums[0] * nums[1] * nums[sz-1],nums[sz-1] * nums[sz-2] * nums[sz-3] );
    
}
// @lc code=end

