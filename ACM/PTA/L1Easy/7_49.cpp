#include<bits/stdc++.h>

using namespace std;
char ch1,ch2,ch3;//起始 目的 过度
int n;
void move(char ch1,char ch2)
{
    printf("%c -> %c\n",ch1,ch2);
}
void obs(int n,char ch1,char ch2,char ch3) //含义 n个盘子 移动 
{
    if(n == 1)
    {
        move(ch1,ch2);//起始到目的
        return;
    }
    //把 n-1 个移动到暂时地方  
    obs(n-1,ch1,ch3,ch2);//将 n - 1 从起始柱子 借助过度柱子移动到 目的柱子
    //n-1移动完了
    move(ch1,ch2);//还是起始到目的
    
    
    //继续移动 n-1到正确地方
    
    obs(n-1,ch3,ch2,ch1);   //将 n - 1个 借助第一个移动到 第二个 
}
int main()
{
    cin>>n;
    getchar();
    cin>>ch1>>ch2>>ch3;
    obs(n,ch1,ch2,ch3);//起始 目的  过度
    return 0;
}