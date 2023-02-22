#include<bits/stdc++.h>


using namespace std;
const int N = 11;
char s[N];
int posbl_soc_1 = 5,rea_soc_1 = 0,posbl_soc_2 = 5,rea_soc_2 = 0;
int main()
{
    scanf("%s",s);
    int cnt = 0;
    for(int i = 0;i<10;i++)
    {
        if((i % 2 == 0)&&(s[i] == '1'))
        {
            rea_soc_1++;
            posbl_soc_1--;
        } else if((i % 2 == 0)&&(s[i] == '0'))
        {
            posbl_soc_1--;
        }

        else if((i % 2 == 1)&&(s[i] == '1'))
        {
            rea_soc_2++;
            posbl_soc_2--;
        }else if((i % 2 == 1)&&(s[i] == '0'))
        {
            posbl_soc_2--;//二号可能减1
        }
        if((rea_soc_1 > rea_soc_2 + posbl_soc_2)||(rea_soc_2 > rea_soc_1 + posbl_soc_1))
        {
            cout<<i + 1<<endl;
            return 0;
        }   

    }
    cout<<"-1"<<endl;
    return 0;
}