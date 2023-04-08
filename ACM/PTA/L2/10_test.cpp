#include <bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node *lchild, *rchild;
};

int n, pre[31], mid[31];
queue<node*> q;

node* create(int pl, int pr, int ml, int mr) {
	if (pl > pr)
		return NULL;
	node* tree = new node();
	tree->data = pre[pl];
	int k;
	for (k = ml; k <= mr; k++)
		if (pre[pl] == mid[k])
			break;
	int lnum = k - ml;
	tree->lchild = create(pl + 1, pl + lnum, ml, k - 1);
	tree->rchild = create(pl + lnum + 1, pr, k + 1, mr);
	return tree;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &mid[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &pre[i]);
	node* root = create(1, n, 1, n);
	q.push(root);
	int ok = 0;
	while (q.size()) {
		node* rot = q.front();
		q.pop();
		if (ok)
			printf(" ");
		ok = 1;
		printf("%d", rot->data);
		if (rot->rchild != NULL)
			q.push(rot->rchild);
		if (rot->lchild != NULL)
			q.push(rot->lchild);
	}
	return 0;
}//7-10