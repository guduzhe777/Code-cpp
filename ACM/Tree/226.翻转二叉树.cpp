// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem226.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void swap(TreeNode* &a,TreeNode* &b)
    {
        TreeNode* tem;
        tem = a;
        a = b;
        b = tem;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        //和一般层序一样  but  需要先放右 再放 左
        //得到完整 数组  从后向前 一步一步赋值
        queue<TreeNode *> queue;
        vector<int> vec;
        vector<vector<int>> result;
        int cnt = 0;
        if (root)
            queue.push(root);
        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *Node = queue.front();
                queue.pop();
                //访问到了该元素 直接交换左右孩子即可
                swap(Node->left, Node->right);
                if (Node->left)
                    queue.push(Node->left);
                if (Node->right)
                    queue.push(Node->right);
            }
        }
        //得到一个标准的 层序遍历数组

        return root;
    }
};
// @lc code=end
