#include<bits/stdc++.h>

using namespace std;
const int N = 110;

int si1[10];
int si2[10];//�ֱ��ж�ԭ���� �������麬�е����ּ�����
string s;//��������
int orig[N];
int change[N];
int main()
{
    cin>>s;
    for(int i = 0; i<s.length(); i++)
    {
        orig[i] = s[i] - '0';
        change[i] = orig[i]*2;//change[i] ԭ���ֵ�double
    }
    for(size_t i = s.length()-1; i>0; i--)
    {
        if(change[i]>9)
        {
            change[i-1] += change[i]/10;
            change[i] %=10;

        }
    }//�õ���λ����
    bool si = true;//Ĭ�����Yes
    if(change[0]>9)
    {
        printf("No\n");
        si = false;
    }
    else
    {
        for(size_t i = 0; i<s.length(); i++) //�����ַ����е�ÿһλ����
        {
            si1[orig[i]]++;//ԭ����
            si2[change[i]]++;//double�������
        }
        for(int i = 0; i<10; i++)
        {
            if(si1[i] == si2[i]) continue;
            else
            {
                printf("No\n");
                si = false;
                break;
            }
        }
    }
    if(si)
    {
        printf("Yes\n");
    }
    for(int i = 0; i<s.length(); i++)
    {
        printf("%d",change[i]);
    }
    printf("\n");
}
