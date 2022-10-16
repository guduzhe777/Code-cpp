/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
//三个负数 -3 -2 -1 1 2 3
//三个正数  1 2 3 4 5 6
//有正有负  -3 -2 1 2 3 6
//          -3 1 2 3
//无非两种情况  最后三个 或者 前三个 比较一下
//我们没有办法一步得到答案 需要结合情况分类讨论
int max(int a,int b)
{
    return a>b?a:b;
}
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        
        //一个参数第一,最后对待排序序列的初始和最终位置的随机访问迭代器。使用的范围是[first, last)，
        //它包含第一个和最后一个之间的所有元素，包括由first指向的元素，但不包括由last指向的元素。
        //RandonAccessIterator应该指向一个恰当定义了交换的类型，并且该类型既可移动构造又可移动赋值。
        //   
    }
};

// @lc code=end

