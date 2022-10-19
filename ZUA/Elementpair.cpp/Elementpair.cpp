#include<iostream>

using namespace std;




void test0()
{
    //输入
    int N,C,arr[101],cnt = 0;
    cin >> N>>C;
    for(int i  = 0;i<N;i++)
    {
        cin >>arr[i];
    }
    //c+arr[1] == arr[1...2..3..4] 
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            // if(arr[j] + C == arr[i])
            // {

            // }
            if(arr[i] + C == arr[j])
            {
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}
void test1()
{
    //任选两个数使其和是k的倍数
    int n,k,cnt = 0;
    cin >> n >>k;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >>arr[i];
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if((arr[i] + arr[j])%k == 0)
            {
                cnt++;
            }
        }
    }   
    printf("%d ",cnt);
}

int main()
{
    //test0();
    test1();
    return 0;  
}