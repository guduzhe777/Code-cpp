#include<iostream>


using namespace std;
typedef int Emdata;
typedef struct ListNode
{
    Emdata num;
    struct ListNode *next;
}Node,*NodePtr;
//创建两个链表
//合并
//有头节点的
//找到尾部 next 赋值 头指针
//头插 
//尾插入
void InitList(NodePtr H)
{
    H->next = NULL;
    
    
}

void InsertList(NodePtr H,int n)
{
    NodePtr p,q;

    //循环找到空 开始插入
    
   p = H;
   q = (NodePtr)malloc(sizeof(Node));
   while(p->next)
   {
    p = p->next;
   }    
    q->num = n;
    q->next = p->next;
    p->next = q;

}
void PrintList(NodePtr H)
{
    NodePtr p;
    p = H->next;
    while(p)
    {
        cout <<p->num <<endl;
        p = p->next;
    }
}
NodePtr Append_List(NodePtr List1,NodePtr List2)
{   
    NodePtr p;
    p = List1;
    while(p->next)
    {
        p = p->next;
    }
    p->next = List2->next;
    return List1;
}
int main(){

    Node List1,List2;
    InitList(&List1);
    InitList(&List2);
    Emdata num,n;
    cin >>n;
    for(int i = 0;i<n;i++)
    {
        cin >> num;
        InsertList(&List1,num);
    }
    for(int i = 0;i<n;i++)
    {
        cin >> num;
        InsertList(&List2,num);
    }
    PrintList(&List1);
    PrintList(&List2);

    NodePtr List0 = Append_List(&List1,&List2);
    PrintList(List0);  

    return 0;
}