

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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> arr;
    stack<TreeNode*> st;
    if(root == NULL)
    {
        return arr;
    }
   
    
    st.push(root);
    while(!st.empty())//不空开始处理
    {
        TreeNode* Nodeptr = st.top();
        st.pop();//取出来需要处理的树
        arr.push_back(Nodeptr->val);//保存
        if(root->right){
             st.push(root->right);
        }
        if(root->left){
              st.push(root->left);
        }
    }//最后 放入 的需要处理数据 全部完成 
    return arr;
    }
};