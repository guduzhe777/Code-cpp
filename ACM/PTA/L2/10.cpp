#include<bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node* lchild,*rchild;
};
const int N = 31;
int pre[N],mid[N];//前序 中序


int n;
node* creat(int ml,int mr,int pl,int pr)
{
    if(pl>pr)
        return NULL;
    node* root = new node();
    root->data = pre[pl];
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
    root->lchild = creat(ml,k-1,pl+1,pl+lnum);
    root->rchild = creat(k+1,mr,pl+lnum+1,pr);

    return root;
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&mid[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&pre[i]);
    }
    node* root = creat(1,n,1,n);

    queue<node*> q;
    q.push(root);
    bool fir = true;
    while(!q.empty())
    {
        node* this0 = q.front();
        q.pop();
        if(fir)
        {
            printf("%d",this0->data);
            fir = false;
        }else{
            printf(" %d",this0->data);
        }
        if(this0->rchild)
            q.push(this0->rchild);
        if(this0->lchild)
            q.push(this0->lchild);
    }
    return 0;
}