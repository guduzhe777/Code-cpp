#include<bits/stdc++.h>

using namespace std;

const int N = 35;
int mid[N];
int pre[N];
int n;
struct node{
	node* lchild,*rchild;
	int data;
};

node* creat(int ml,int mr,int pl,int pr)
{
	if(pl>=pr)
		return NULL;
	node* root = new node();
	root->data = pre[ml];
	int k;
	for(k = 0;k<mr;k++)
	{
		if(mid[k] == root->data)
			break;
	}
	int lnum = k - ml;
	root->lchild = creat(ml,k,pl+1,pl+1+lnum);
	root->rchild = creat(k+1,mr,pl+lnum+1,pr);
	
	return root;
}
int main()
{
	cin>>n;	
	for(int i = 0;i<n;i++)
	{
		cin>>mid[i];
	}
	for(int i = 0;i<n;i++)
	{
		cin>>pre[i];
	}
	node* root = creat(0,n,0,n);
	printf("%d",root->data);
	return 0;
}
