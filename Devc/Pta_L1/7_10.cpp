//���̶ܳ�  w  ��  ����гɷ��� s  w = 1/s;
//������ǵ���ġ�  С����С�컼�˵���˼
//��С�������п�ȥ������С��֮��ľ���Ϊ 1��ֻ��һ�㴰��ֽ��
//����С��֮��ľ���Ϊ 108000
//���������ʶ����֮���ǿɴ��ݵġ�
//����С�̾����Լ���С��֮��ľ���Ϊ 2����ʹС�̲���ֱ����ʶС�죬����ҲĬ��С����������ʶС�죬
//С�̻�����Լ���С��֮��ľ���Ϊ 1+2=3

//������ͨ��������Ҳ����ʶС�죬��ͨ����ͬ�����Ƶ������ľ���в�һ��������ô���أ�
//С�̶�С��ľ���ж���Ϊ�����Ƶ������ľ���е���Сֵ��
//Ů��Ե��һ���˵�����Ե��������ϲ����/�����Ǹ����Ծ����ģ������ɶ���/�����޸е��Ǹ����Ծ����ġ�
//���Ǽ�һ���� i ��һ������ j ���еľ����Ϊ D ij ����i  j ��ά���� ������߾����
//�� i �ġ�����Ե������Ϊ 1/max j��S(i)? {D ij? } ����Ե��� max j��S(i)? {D ij? } ��С
//������һ��������֮��ľ�����зֱ��ҳ������Ա��еġ��������ˡ���
// N����500����Ϊ��������
//
 //�Ա� K ����1:����1 ����2:����2 ���� ����K:����K
//���� N ��N��  i�� ��Ӧ ���i   �� i �й�ϵ���� ����  ����ά����
//��θ�ֵ��
//С�̶�С��ľ���ж���Ϊ�����Ƶ������ľ���е���Сֵ��
//min(st[i,j],dis) 
//Ѱ������ Ů��  �Ա� ��ǣ� si[i] i 1Ϊ��  0ΪŮ
//���� Ů ��Ѱ��������//��/�����޸е��Ǹ����Ծ�����
//���� ÿ��i��˵ ����ͬ�Ծ��������С  Ѱ�� ����������� 
// //�Ա� K ����1:����1 ����2:����2 ���� ����K:����K::getline();

//�����ַ���
//�õ���ά�����ϵ
//��ͬ�� ��ֵ ��С 
//�ڶ�ά������ Ѱ������ ����(pair������� i,max0) Ȼ�� �������Ƚ���С��
//
#include<bits/stdc++.h>

using namespace std;
const int N = 510;
int st[N][N];
int n;
bool si[N];//�������  s[i]Ϊ1  iΪ�� 
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)//���i  ��i�� 
    {
        string s;
        getline(cin,s);
						//δ��ȫ����  ȫ���� ������ ����������
						// һ��һ������ 
						
        if(s[0] == 'M') si[i] = 1; //���i Ϊ��/Ů 
        	else{
        		si[j] = 0;
			}
		int cnt = s[2] - '0';//�뼸���˵�������ϵ
			 
        for(int j = 0;j<cnt;j++)
        {
        	
		}
    }
    
    return 0;
}
