#include<bits/stdc++.h>
using namespace std;

//���� 
//Ѱ����������  ��������    �ظ�����  
//
int n;// �û���
const int N = 10e6+10;// 
int si[N];  //si[i] = 2; //��ǩi �����  ��i�� ��������   
struct peo{
    char name[21];
    int  suport,rept,cnt;//��������suport  �ظ����� rept ����ǩ  ���� cnt rept/cnt = avg  ���� ƽ������
    double avg;
};
peo peo0[110];//��� 100�û� 
int cnt;
bool cmp_peo(peo peo1,peo peo2)//�ȽϽṹ�� 
{
	if(peo1.suport>peo2.suport) return true;
	if(peo1.cnt<peo2.cnt&&peo1.suport == peo2.suport) return true;
	return false;// ��������   ��ǩ ƽ��ֵ�������� ���ش��� 
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++) //n���û� 
    {
    	memset(si,0,sizeof(si));//Ĭ�� ȫû���� 
        cin>>peo0[i].name>>peo0[i].cnt;//��ǩ���ִ���  
        for(int k = 0;k<peo0[i].cnt;k++)//����������� 
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
//			 if(si[j]>1)//����ĳ�� ��Ƶ��ε��� 
//			 {
//			 	peo0[i].cnt++;//�ظ����ޱ������ 
//			 	peo0[i].rept += si[j] - 1;//�ظ����� ����
//			 }
//		 }
//		 if(peo0[i].cnt)
//		 {
//		 	peo0[i].avg = (double)peo0[i].rept / peo0[i].cnt;
//		 }else{
//		 	peo0[i].avg = 0;//�ظ�����Ϊ0 
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
