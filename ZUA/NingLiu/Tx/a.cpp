#include <iostream>

#include <algorithm>

#include <cstring>

#include <cstdio>

using namespace std;



int main()

{

    int i,n,j,k,minx;

    int s;

    double t;

    int a[10005],b[1005];

    while(cin>>n>>s) // 输入顾客数量和可供等待的工位

    {

        for(i=0; i<n; i++)

            cin>>a[i]; 

        sort(a,a+n); 

        memset(b,0,sizeof(b)); 

        for(i=0; i<n; i++)

        {

            minx=0x7fffffff; 

            k=0; //

            for(j=0; j<s; j++)  //有几个工位 进行几次循环

            {

                if(minx>b[j]) // 这个和上个小的进行对比

                {

                    minx=b[j]; //记录小的

                    k=j; //记录小的对应的工位

                }

            }

            b[k]+=a[i]; // b[k] = b[k] + a[i]  记录每个工位的总时间

            a[i]=b[k];  // 把每个工位的时间赋给对应顾客 形成 顾客总时间数组

        }

        t=0;

        for(i=0; i<n; i++) // 计算顾客平均等待时间

            t+=a[i];

        t/=n;

        printf("%d\n",(int)(t));

    }



    return 0;



}

