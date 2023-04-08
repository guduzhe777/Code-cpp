#include<bits/stdc++.h>

using namespace std;
typedef int emdata;
struct node{
    emdata data;
    node* lchild,*rchild;//左右孩子
};
const int N = 31;
emdata mid[N];
emdata post[N];//后序
int n;
node* creat(int ml,int mr,int pl,int pr)//后 + 中
{
    if(pl>pr)
        return NULL;
    node*root = new node();
    root->data = post[pr];
    int k;
    for(k = ml;k<=mr;k++)
    {
        if(root->data == mid[k])
            break;
    }
    //找到 中序树根节点
    int lchildnum = k - ml;//孩子数量 得到最后一个下标
    root->lchild = creat(ml,k-1,pl,pl + lchildnum-1);//
    root->rchild = creat(k+1,mr,pl+lchildnum,pr-1);
    return root;//返回 该树的根
}
void dfs(node *root)
{
    if(root == NULL)
        return;
    printf(" %d",root->data);//中
    dfs(root->lchild);   //左
    dfs(root->rchild);   //右
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&post[i]);
    }
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&mid[i]);
    }
    node* root = creat(1,n,1,n);//中序 树开始 结束 后序 树开始 结束

    //前序遍历
    printf("Preorder:");
    dfs(root);
    return 0;
}