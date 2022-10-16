#include<iostream>

using namespace std;



int main()
{
    //记录游戏次数 cnt
    //多次输入答案 且 多次输入猜的 两个循环
    //
    //创建数组answer guess保存 答案 猜的
    //判断相同位置 且 把相同位置删除 防止影响
    //双层循环 一个对比 多个
    int cnt = 0,answer[1000],answer1[1000],guess[1000],n,sum = 0;
    while(1)
    {
        while(scanf("%d",&n)&&(n))
        {
            cnt++;
            printf("Game %d:\n",cnt);
            for(int i = 0;i<n;i++)
                {
                    scanf("%d",&answer[i]);
                    answer1[i] = answer[i];
                }
                //输入完答案序列
            for(;;)
            {
                //可以多次输入猜的序列 且每一次猜都需要 重置次数（相同不同）
                int cnt_same = 0,cnt_dif = 0;    
                for(int i = 0;i<n;i++)
                {
                    scanf("%d",&guess[i]);
                }
                for(int i = 0;i<n;i++)      //如何判断八个都非0？
                {
                    sum += guess[i];
                }
                if(!sum)
                {
                    
                    break;
                }
                //用完就更新 下一次用
                sum = 0;
                //相同
                for(int i = 0;i<n;i++)
                {
                    if(answer[i] == guess[i])
                    {
                        cnt_same++;
                        answer[i] = -100000;
                        guess[i] = -1000000;
                    }
                }
                //不同
                for(int i = 0;i<n;i++)
                {
                   for(int j = 1;j<n;j++)
                {
                    if((answer[i] == guess[j]))
                    {
                        cnt_dif++;
                        
                    }
                }
                }

                for(int i = 0;i<n;i++)
                {
                    answer[i] = answer1[i];
                }
                
                printf("(%d,%d)\n",cnt_same,cnt_dif);
                
                

            }




        }
    }

    return 0;
}