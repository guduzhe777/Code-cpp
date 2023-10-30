#include <bits/stdc++.h>
#define N 100
using namespace std;

string s1, s2, s;
int maxlength[N][N];
int direct[N][N];
void OutPutLCS(int B[][N], string X,int str1_len,int str2_len)
{
	
	if (str1_len == 0 || str2_len == 0)
	{
		return;
	}
	if (B[str1_len][str2_len] == 0)   //箭头左斜 当前位 字符数值相同
	{
		OutPutLCS(B, X, str1_len - 1, str2_len - 1);
		printf("%c", X[str1_len - 1]);
	}
	else if (B[str1_len][str2_len] == -1)
	{
		OutPutLCS(B, X, str1_len - 1, str2_len);
	}
	else
	{
		OutPutLCS(B, X, str1_len, str2_len-1);
	}
}
 
int main()
{

    // ios::sync_with_stdio(false);
    
    cin >> s1 >> s2;
    //二者之间的公共相同子串长度
    //初始方向：

    int len1 = s1.length(), len2 = s2.length();
    for (int i = 0; i <= len1; i++)
        direct[i][0] = -2;
    for (int i = 0; i <= len2; i++)
        direct[0][i] = -2; //初始化 因为最边界一般可能没有方向 而 里面可能有放行

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                maxlength[i][j] = maxlength[i - 1][j - 1] + 1;
                direct[i][j] = 0; //-1左 0左上 1上
            }
            else
            {
                maxlength[i][j] = max(maxlength[i - 1][j], maxlength[i][j - 1]);
                if (maxlength[i - 1][j]>=maxlength[i][j - 1])
                {
                    direct[i][j] = -1;

                    
                }
                else
                {
                    direct[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            cout<<maxlength[i][j]<<" ";
        }
        printf("\n");
    }
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            cout<<direct[i][j]<<" ";
        }
        printf("\n");
    }
    OutPutLCS(direct,s1,len1,len2);
    return 0;
}