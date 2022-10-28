#include <iostream>
#include <vector>
using emdata = int;
using namespace std;
typedef struct Tree{
    struct Tree *l;
    struct Tree *r;
    emdata data;
}Tree,*Tree_Poi;
void Tree_IntiNode(Tree_Poi Tree_H)//默认没有子节点
{
    Tree_H->l = NULL;
    Tree_H->r = NULL;
}
void Dfs_Pre(Tree_Poi Tree_H,emdata tem[])
{

}
void Add_Node(Tree_Poi Tree_H)//左右一起添加
{
    Tree_H->l = (Tree_Poi)malloc(sizeof(Tree));
    Tree_H->r = (Tree_Poi)malloc(sizeof(Tree));
}
int main()
{
    Tree_Poi Tree_H;
    emdata tem[101];
    Tree_Inti(Tree_H);
    
    Dfs_Pre(Tree_H,tem);

    return 0;
}
