思路：

对应层序遍历：

二叉树无法同时访问左边又访问右边

所以我们放到队列中  

用数量 作为 一层的标记

在取的时候 放进 这个节点的 左右节点

实现 前面总是 一层 用 大小 进行标记

因为  我们时刻会对队列放 子节点

如果队列真的没有节点了说明全拿走了  没有再放子节点   那么 说明遍历完了

#### 过程

for 中 是一个在队列边取  边在队列放 size记录一层有多少个 既是取多少个

1. 不断取出来父节点 放入子节点最后到最后一行 只取不放 那么  队列空就完了  

~~~
whiwhile (!que.empty())
~~~

2. 取出来队列的的长度 获取 这一层的长度  等待取出

   1. ~~~
        	int size = que.size();
      ~~~

   2. 

从第一层开始就固定  经历下面循环 取出一层  留下 下一层

~~~

	for i 0 to size //size代表取出来几个
	Node = queue.pop(); 
	vec.push_back(node->val);取出后保存一下节点元素
	if(Node->left) queue.push()
	if(Node->left) queue.push()//边取边放
	

~~~

3. ​	循环处理完这一层 就被保存 放到二维数组中 

4. ~~~
   	result.push(vec);
   ~~~

5. 





~~~

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;       
        vector<int> vec;
        vector<vector<int>> result;
        if(root)  queue.push(root);

        while(!queue.empty())
        {
            int size = queue.size();//代表一层中的元素个数
            for(int i = 0;i<size;i++)//处理这些元素   //需要处理的元素是固定的 直接用的queue size会变的
            {
                TreeNode* Node = queue.top();     
                queue.pop();
                vec.push_back(Node->val);//保存
                //放儿子
                if(Node->left) queue.push(Node->left)
                if(Node->right) queue.push(Node->right);
            }
            result.push_back(vec);
        }
        
    }
};
~~~

应用：层序遍历  好处就是 能够判断你到底是第几个 

如果右视图  那么 只看到 这一层的最后一个即可

~~~
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //层序？  只放最右边 完美
        //深度？  一直递归
        queue<TreeNode*> queue;
        vector<int>vec;
        if(root) queue.push(root);
        while(!queue.empty())
        {
            int size = queue.size();
            for(int i = 0;i<size;i++)
            {
                TreeNode* Node = queue.front();
                queue.pop();
                if(i == size - 1) vec.push_back(Node->val); //单层最后一个  ！！！ 这才是层序的原因
                if(Node->left) queue.push(Node->left);
                if(Node->right) queue.push(Node->right);

            }
        }
        return vec;
    }
};
~~~

//如何实现 只访问 最后一个

层序办法就是  只看最后一个  或者 遍历到最后一个  我就放到数组

递归就是 一直向 最右边 访问 

0. 迭代法：

~~~
一切节点都是中节点   且 模拟栈

放节点 略

最后一层的时候  最左也变成了 无叶子节点的新树


~~~

1. 不是0： 那么 不断放  在栈中 放入三个节点 切记倒序

~~~
if(st.top != NULL)
{
	st.pop();//把这个元素拿出来 按顺序防止 
	//以中序为例子 左 中 右 那么 右 中 左
	st.push(左);
	st.push(中);
	st.push(NULL);
	st.push(右);
}
~~~



2. 如果找到0 那么  保存 取出

~~~
st.pop();
vec.push_back(Node->val);
st.pop();
~~~



