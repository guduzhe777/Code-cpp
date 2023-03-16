// // #include<bits/stdc++.h>

// // using namespace std;
// // //一天时间 可以被独一无二的标记
// // //转化
// // //只标记 开始结束即可
// // //对  i + 1 判断 //数组保存标记？
// // const int N =100010;
// // bool sign[N];
// // int n;
// // int dis[N];//对应 下标i的这一段的时间
// // void set_Sign(int sum1,int sum2)//设置 占用的时间
// // {
// //     for(int j = sum1 ;j<sum2;j++)
// //     {
// //         sign[j] =true;//标记被使用
// //     }
// // }
// // int get_Time(string s)
// // {
// //     int sum1 = 0,sum2 = 0;
// //     int h1,m1,s1,h2,m2,s2;
// //     sscanf(s.c_str(),"%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
// //     sum1 = h1 * 3600 + m1 * 60 + s1;
// //     sum2 = h2 * 3600 + m2 * 60 + s2;
// //     set_Sign(sum1,sum2);
// // }

// // int main()
// // {
// //     cin>>n;
// //     getchar();
// //     while(n--)
// //     {
        
// //         string s;
// //         getline(cin,s);
// //         get_Time(s);    
// //     }
// //     for(int i = 0;i<= 86400;i++)  //下标代表时间
// //     {
// //         if(sign[i] == false)//未使用
// //         {
// //             int tem = i;
            
// //             int h = tem/ 3600, m = tem % 3600 / 60, s = tem % 60;
// //             printf("%02d:%02d:%02d -",h,m,s);
// //             bool sign0;
// //             for(int j = i;j<86400;j++)
// //             {
// //                 if(sign[j])//找到了 被用的开端时间
// //                 {
// //                     h = j / 3600, m = j % 3600 / 60, s = j % 60;
// //                     printf(" %02d:%02d:%02d\n",h,m,s);
// //                     i = j  + dis[j];//
// //                     sign0 = true;
// //                     break;
// //                 }
                
// //             } 
// //             if(!sign0)//最后一个时刻 未被 使用 //最后一个时刻反复被赋值 true;
// //             {
// //                 printf(" 23:59:59\n");
// //                 break;
// //             }
// //             sign0 = false;
// //         }
// //     }
// //     return 0;
// // }
// // #include<bits/stdc++.h>

// // using namespace std;
// // //一天时间 可以被独一无二的标记
// // //转化
// // //只标记 开始结束即可
// // //对  i + 1 判断 //数组保存标记？
// // const int N =100010;
// // bool sign[N];
// // int n;
// // int dis[N];//对应 下标i的这一段的时间
// // void set_Sign(int sum1,int sum2)//设置 占用的时间
// // {
// //     for(int j = sum1 ;j<sum2;j++)
// //     {
// //         sign[j] =true;//标记被使用
// //     }
// // }
// // int get_Time(string s)
// // {
// //     int sum1 = 0,sum2 = 0;
// //     int h1,m1,s1,h2,m2,s2;
// //     sscanf(s.c_str(),"%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
// //     sum1 = h1 * 3600 + m1 * 60 + s1;
// //     sum2 = h2 * 3600 + m2 * 60 + s2;
// //     set_Sign(sum1,sum2);
// // }

// // int main()
// // {
// //     cin>>n;
// //     getchar();
// //     while(n--)
// //     {
        
// //         string s;
// //         getline(cin,s);
// //         get_Time(s);    
// //     }
// //     for(int i = 0;i<= 86400;i++)  //下标代表时间
// //     {
// //         if(!sign[i])
// //         {
// //             for(int j = i;j<=86400;j++)
// //             {
// //                 if(sign[j])
// //                 {
// //                     int h1 = i / 3600,m1 = i % 3600 / 60,s1 = i % 60;
// //                     int h2 = j / 3600,m2 = j % 3600 / 60,s2 = j % 60;
// //                     printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
// //                     i = j;
// //                     break;
// //                 }else  if(j == 86400)//找到最后了 还是没有找到被使用时间
// //                 {
// //                     int h1 = i / 3600,m1 = i % 3600 / 60,s1 = i % 60;
// //                     printf("%02d:%02d:%02d - 23:59:59\n",h1,m1,s1);
// //                     i = j + 1;
// //                 }
                
// //             }
            
// //         }
// //     }
// //     return 0;
// // }

#include<bits/stdc++.h>

using namespace std;
//一天时间 可以被独一无二的标记
//转化
//只标记 开始结束即可
//对  i + 1 判断 //数组保存标记？
const int N =100010;
bool sign[N];
int n;
int dis[N];//对应 下标i的这一段的时间
void set_Sign(int sum1,int sum2)//设置 占用的时间
{
    for(int j = sum1 ;j<sum2;j++)
    {
        sign[j] =true;//标记被使用
    }
}
int get_Time(string s)
{
    int sum1 = 0,sum2 = 0;
    int h1,m1,s1,h2,m2,s2;
    sscanf(s.c_str(),"%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
    sum1 = h1 * 3600 + m1 * 60 + s1;
    sum2 = h2 * 3600 + m2 * 60 + s2;
    set_Sign(sum1,sum2);
}

int main()
{
    cin>>n;
    getchar();
    while(n--)
    {
        
        string s;
        getline(cin,s);
        get_Time(s);    
    }
    int i,j;
    for(i = 0;i< 86400 - 1;i++)  //下标代表时间  //访问不到 最后一个 false即可 
    {
        if(sign[i]) continue;
        for(j = i + 1;j<86400-1;j++)
        {
            if(sign[j]) break;
        }
        int h1 = i / 3600,m1 = i % 3600 / 60,s1 = i % 60;
        int h2 = j / 3600,m2 = j % 3600 / 60,s2 = j % 60;
        printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        i = j;
    }
    return 0;
}
