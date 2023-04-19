#include<bits/stdc++.h>

using namespace std;


int post[36],mid[36];

int n;

struct node{
    node* lchild,*rchild;
    int data;
};

//如何建树
//左树数量  与 左闭右开 
node* creat(int ml,int mr,int pl,int pr)
{
    if(pl>=pr)
        return NULL;
    node* root =  new node();
    int data = post[pr-1];
    root->data = data;
    int k;
    for( k = 0;k<n;k++)
    {
        if(mid[k] == data)
        {
            break;
        }
    }
    //得到k
    int lnum = k - ml;
    root->lchild = creat(ml,ml+lnum,pl,pl+lnum);
    root->rchild = creat(ml+lnum+1,mr,pl+lnum,pr-1);
    return root;
}
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>post[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin>>mid[i];
    }
    node *root = creat(0,n,0,n);
    
    queue<node*> q;
    q.push(root);
    bool fir = true;
    while(!q.empty())
    {
        node* father = q.front();
        q.pop();
        if(fir)
        {
            fir = false;
            printf("%d",father->data);
        }else{
            printf(" %d",father->data);
        }
        if(father->lchild)
            q.push(father->lchild);
        if(father->rchild) 
            q.push(father->rchild);
    }
    return 0;
}