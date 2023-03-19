#include<bits/stdc++.h>
using namespace std;

//输入 
//寻找两个变量  点赞数量    重复数量  
//
int n;// 用户数
const int N = 10e6+10;// 
int si[N];  //si[i] = 2; //标签i 被标记  且i被 点赞两次   
struct peo{
    char name[21];
    int  suport,rept,cnt;//点赞数量suport  重复数量 rept 个标签  数量 cnt rept/cnt = avg  就是 平均数量
    double avg;
};
peo peo0[110];//最多 100用户 
int cnt;
bool cmp_peo(peo peo1,peo peo2)//比较结构体 
{
	if(peo1.suport>peo2.suport) return true;
	if(peo1.cnt<peo2.cnt&&peo1.suport == peo2.suport) return true;
	return false;// 点赞数量   标签 平均值都不符合 返回错误 
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++) //n个用户 
    {
    	memset(si,0,sizeof(si));//默认 全没点赞 
        cin>>peo0[i].name>>peo0[i].cnt;//标签出现次数  
        for(int k = 0;k<peo0[i].cnt;k++)//输入点赞数量 
        {
        	int tem;
        	cin>>tem;
        	si[tem]++;
		} 
		 for(int j = 1;j<N;j++)
		 {
		 	 
		 	if(si[j])
		 	{
		 		peo0[i].suport++;
			 }
		}
//			 if(si[j]>1)//对于某个 视频多次点赞 
//			 {
//			 	peo0[i].cnt++;//重复点赞编号数量 
//			 	peo0[i].rept += si[j] - 1;//重复点赞 数量
//			 }
//		 }
//		 if(peo0[i].cnt)
//		 {
//		 	peo0[i].avg = (double)peo0[i].rept / peo0[i].cnt;
//		 }else{
//		 	peo0[i].avg = 0;//重复数量为0 
//		 }
		 
		 
    }
//     for(int i = 1;i<=n;i++)
//     {
//     	printf("%s : %d %d %d %lf \n",peo0[i].name,peo0[i].suport,peo0[i].rept,peo0[i].cnt,peo0[i].avg);
// 	}
    sort(peo0+1,peo0+n+1,cmp_peo);
//     for(int i = 1;i<=n;i++)
//     {
//     	printf("%s : %d %d %d %lf \n",peo0[i].name,peo0[i].suport,peo0[i].rept,peo0[i].cnt,peo0[i].avg);
// 	}
    if(n < 3)
    {
        for(int i = 1;i<=n;i++) 
    {
        if(i == 1)
        {
            printf("%s",peo0[i].name);
        }else{
            printf(" %s",peo0[i].name);
        }
    }
        for(int i = 0;i<3 - n;i++)
         {
    	if(n == 0&&i == 0)
        {
            printf("-");
        }else{
            printf(" -");
        }
	}
    }else{
        for(int i = 1;i<=3;i++) 
    {
        if(i == 1)
        {
            printf("%s",peo0[i].name);
        }else{
            printf(" %s",peo0[i].name);
        }
    }
    }
    
    
    printf("\n");
    return 0;
}
