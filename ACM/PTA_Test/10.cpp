#include<bits/stdc++.h>

using namespace std;

int seconds[86400];

int get_time(int h,int m,int s)
{
    return h * 3600 + m * 60  + s;
}
int main()
{

    int n;
    cin>>n;
    int st_h,st_m,st_s,end_h,end_m,end_s;
    while(n--)
    {
        scanf("%d:%d:%d - %d:%d:%d",&st_h,&st_m,&st_s,&end_h,&end_m,&end_s);
        int start = get_time(st_h,st_m,st_s);
        int end = get_time(end_h,end_m,end_s);
        for(int i = start;i<end;i++)
        {
            seconds[i] = true;
        }
    }
    for(int i = 0;i<86400;i++)
    {
        if(!seconds[i])
        {
            for(int j = i + 1;j<86400;j++)
            {
                if(seconds[j]||j == 86400-1)
                {
                    //找到开始  i  结束j
                    st_h = i / 3600,st_m = i % 3600 / 60,st_s = i % 60,end_h = j/ 3600,end_m = j % 3600 / 60,end_s = j % 60;
                    printf("%02d:%02d:%02d - %02d:%02d:%02d\n",st_h,st_m,st_s,end_h,end_m,end_s);
                    i = j;
                    break;
                }
            }
        }
    }
    return 0;
}