#include<bits/stdc++.h>


using namespace std;

struct node{
    int data;
    node* lchild,*rchild;
};

int n;
const int N = 31;
int post[N],mid[N];
node* creat(int ml,int mr,int pl,int pr)
{
    if(pl>pr)//该树 没有节点
        return NULL;
    node* root = new node();
    root->data = post[pr];
    int k;
    for(k = ml;k<=mr;k++)
    {
        if(root->data == mid[k])
        {
            break;
        }
    }
    int lnum = k - ml;
    int rnum = mr - k;
    root->lchild = creat(ml,k-1,pl,pl+lnum-1);
    root->rchild = creat(k+1,mr,pl+lnum,pr-1);

    return root;
}

void dfs(node* root)
{

    if(root == NULL)
        return;
    printf("%d ",root->data);

    dfs(root->lchild);
    dfs(root->rchild);
}
int main()
{
    cin>>n;
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&post[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&mid[i]);
    }
    node* root = creat(1,n,1,n);
    // dfs(root);
    //层序遍历
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* this0 = q.front();
        q.pop();
        printf("%d ",this0->data);
        if(this0->lchild)
            q.push(this0->lchild);
        if(this0->rchild)
            q.push(this0->rchild);
        
    }
    return 0;
}