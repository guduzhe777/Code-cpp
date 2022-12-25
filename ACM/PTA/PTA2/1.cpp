#include<iostream>
#include<string>

using namespace std;
using Emdata = char; 

typedef struct Tree{
    Emdata data;
    struct Tree* LChild;
    struct Tree* RChild;
}Tree_Node,*Tree_Ptr;
//还原二叉树 实际 对前中后序 的 分节点 个数 的过程
Tree_Ptr Tree_get(Emdata a[],Emdata b[],int i,int j, int s,int t) //j - i + 1分的节点的个数(i == j) 有一个
{
    if(i>j) return NULL;
    //分别求 左树  右树 
    Tree_Ptr NodePtr = (Tree_Ptr)malloc(sizeof(Tree_Node)); 
    NodePtr->data = a[i];//根节点
    int k = s; //从 头部 开始 寻找 a[i]  且  得到 左树 需要几个节点 （还有个 数目 与 下标关系呢） 因为 前面 都是 左树
    while(k<t&&a[i] != b[k]) k++; //分成左右树  且 一定能找到  k == t 说明最后一个了 找到了  
    NodePtr->LChild = Tree_get(a,b,i + 1, k - s + i,s,k-1);
    //余下的 都是 右树的  
    NodePtr->RChild = Tree_get(a,b,k - s + i + 1,j,k + 1,t);
    return NodePtr;    
}
int max(int a,int b)
{
    return a>b?a:b;
}
int Tree_getdepth(Tree_Ptr Tree)
{
    if(!Tree) return 0;
    int l = Tree_getdepth(Tree->LChild);
    int r = Tree_getdepth(Tree->RChild);
    int depth = 1 + max(l,r);
    return depth;
}

int main()
{
    int num;
    cin>>num;
    Emdata pre[num],in[num];
    
    cin>>pre>>in;
    
    Tree_Ptr Tree_ret = Tree_get(pre,in,0,num - 1,0,num - 1);//num 为 个数 与 下标相差1
    int depth = Tree_getdepth(Tree_ret);
    printf("%d",depth);
    return 0;
}