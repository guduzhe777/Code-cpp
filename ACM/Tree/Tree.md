#### 两种存储方式：

1. 链子 

   1. ~~~
      typedef struct Tree{
          struct Tree *l;
          struct Tree *r;
          emdata data;
      }Tree,*HTree;
      ~~~

   2. 

2. 顺序  用数组   下标i 那么子树2 * i + 1 2 * i + 2就是i的 左右子树

#### 遍历： 总的是基于递归原理---栈 所以模拟栈  

无非放入栈的方式不同  取出来的方式不同

中序：

1.   //并不是 说 直接 保存左 保存中 右 而是 不断进入新树  左为空 返回 那么保存中  这个中为上一个的左  这就是保存左！

2. ~~~
   
    //中序：先左 左  左 不断进入新树  然后 保存
   class Solution {
   public:
       void dfs_mid(TreeNode* root,vector<int> &arr)
       {
           if(root == NULL)
           {
               return;
           }
           dfs_mid(root->left,arr);//左
           arr.push_back(root->val);//中
           dfs_mid(root->right,arr);//右
           //并不是 说 直接 保存左 保存中 右 而是 不断进入新树  左为空 返回 那么保存中  这个中为上一个的左  这就是保存左！
   
       }
       vector<int> inorderTraversal(TreeNode* root) {
           vector<int> arr;
           dfs_mid(root,arr);
           return arr;
       }
   };
   ~~~



2. 后序：

   1. ~~~
      class Solution {
      public:
          void dfs_post(TreeNode* root,vector<int> &arr)
          {
              if(root == NULL)
              {
                  return;
              }
              dfs_post(root->left,arr);
              dfs_post(root->right,arr);
              arr.push_back(root->val);
          }
          vector<int> postorderTraversal(TreeNode* root) {
              vector<int> arr;
              dfs_post(root,arr);
      
              return arr;
          }
      };
      ~~~

   2. 



#### 迭代方法：

理论：用栈保存新树   用栈pop  操作新树   到了新树  保存数据  处理其左右 （把左 右 树放在栈中）操作

1. 递归类似栈 所以我们迭代模拟栈来实现

2. 过程：以前序为例子： 中左右

   1. 用栈保存需要处理的树 

      1. ~~~
         		TreeNode* Nodeptr = st.top();//处理的当前树
            		st.pop();//取出来需要处理的树
                 arr.push_back(Nodeptr->val);//保存
         ~~~

      2. 

   2. 因为先进后出特性 所以    先放右树  再放左树

      1. ~~~
         		if(Nodeptr->right){  Nodeptr为该节点
                      st.push(Nodeptr->right);
                 }
                 if(Nodeptr->left){
                       st.push(Nodeptr->left);
                 }
                 //放进去等待处理
         ~~~

      2. 

   3. 只要栈不为空 说明有 需要处理的树  

~~~
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
   // 只要栈不为空 说明有 需要处理的树  
    while(!st.empty())//不空开始处理
    {
        TreeNode* Nodeptr = st.top();//处理的当前树
        //中左右  保存中 
        st.pop();//取出来需要处理的树
        arr.push_back(Nodeptr->val);//保存
        // 用栈保存需要处理的树 
        //因为先进后出特性 所以    先放右树  再放左树
        if(Nodeptr->right){
             st.push(Nodeptr->right);
        }
        if(Nodeptr->left){
              st.push(Nodeptr->left);
        }
    }//最后 放入 的需要处理数据 全部完成 
    return arr;
    }
};
~~~

如果是 后序：左右中  向数组中输入  中右左 最后倒序输出 左右中  即可了



#### 中序： 一直向左  空则返回中间（用栈记录返回）再向右

因为 遍历（栈保存）和处理（数组保存）不一致 所以用个 指针来指向需要处理的

过程：如果 需要处理(curr)的没完 或者 需要有顺序遍历（栈保存）的也没完 那么一直处理

一般是一直向左访问  且记录顺序

~~~
if(curr!=NULL)  curr = curr->left;  st.push(curr);
~~~

  如果到空  那么就到中间  arr 保存

~~~
 TreeNode* Node = st.top(); st.pop();  返回中间保存  最后向右 curr = Node->right
~~~

注意：向右一次  一般都是向左   若出现 一个节点 左空 保存中间 右空  那么返回到父的父 节点 也就是 栈 pop

~~~
else(if curr == NULL){ 
	node = st.top(); st.pop() arr = node->val //保存 然后右边 curr = Node->right;
}
~~~



~~~
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr;
        stack<TreeNode*> st;
        vector<int> arr;
        curr = root;
        while(curr != NULL||!st.empty())
        {
            if(curr != NULL)
            {
                st.push(curr);//记录遍历顺序
                curr = curr->left;//一直向左访问
                
            }else{    //终于为空
                TreeNode* Node = st.top();
                st.pop();//吐出来 子的中间  是别人的左
                arr.push_back(Node->val);//保存中间
                curr = Node->right;// 对中间节点 向右  一次  不空那么一直向左 空了保存 中间再向右 
                                    //一直等到 curr == NULL 没有下一个了 栈中需要有顺序遍历的 也遍历完了

            }
        }
        return arr;
    }
};
~~~



中序：左中右 右中左 放入 栈

前序：中左右 右左中 放入 栈

后序：左右中  中右左 放入 栈

处理的是栈  只要栈不空就 一直处理  

#### 一直在做的是两件事情

1.  右 中 NULL 左节点（中序）  入栈 程序 

   1. 注意入栈方式

   2. ~~~
      				st.pop();
                      //前序： 中左右  右左中
                      if(Node->right) st.push(Node->right);
                      if(Node->left) st.push(Node->left);
                      st.push(Node);
                      st.push(NULL);
      ~~~

   3. 最后都会变成中节点 然后输出

      

2. 到达空 错  应该是  一直尝试 变成中节点  后面带有NULL标记 进行输出

   1. ~~~
       			  else(ifst.top() == NULL)			st.pop();
                      arr.push_back(st.top()->val);//保存中间
                      st.pop();//保存 然后 pop 
      ~~~

   2. 

拿中序举例子

对 中元素 进行NULL标记  为什么？  因为中 可以代表任何节点（其他不一定  一定是右节点？ 自己想一想就知道不可能）  

如果该节点 不为空  那么将 右 中 NULL  左保存在栈中 

（过程注：只有一个节点的树  不为空  那么它就变成中节点  后面带NULL ）

那么st.top() == NULL 自然输出这个   

输出之后 再输出 他作为子节点的父亲中节点 后面 NULL  输出 

然后就是他的右节点了  再做一次  右 中NULL 左入栈 程序 



~~~
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //相同代码 只需要调节顺序的迭代：
        //1.入栈  2.变成中节点

        stack<TreeNode*> st;
        vector<int> arr;
        if(root) st.push(root);

        while(!st.empty())
        {
            TreeNode* Node = st.top();
            if(st.top() != NULL)
            {
                st.pop();
                //前序： 中左右  右左中
                if(Node->right) st.push(Node->right);
                if(Node->left) st.push(Node->left);
                st.push(Node);
                st.push(NULL);

            }else{      //含有空的时候 一定为中 那么输出即可
                st.pop();

                arr.push_back(st.top()->val);//保存中间
                st.pop();//保存 然后 pop 
            }
        }
        return arr;
    }
};
~~~



### Tree_dfs.cpp

