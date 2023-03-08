// // i
// (1≤i≤8
// ) 从左向右数的第 i
//  个数字和第 9−i
//  个数字

//从在日期里判断回文数 变成 在回文数里判断日期
//在少的里面找寻东西  总比 在多的里面找寻要简单
//回文数
//日期范围
//合法性
#include<bits/stdc++.h>

using namespace std;
int cnt;
int data1,data2;
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
// bool check_Vaild(int data)//检测日期合法性
// {
//     //分别年月日合法
//     int years = data / 10000;
//     int mouth = data / 100 % 100;
//     int days = data % 100;
//     if(mouth == 0||mouth>12) return false;
//     if(!days) return false;//等于0
//     if(mouth != 2 && days != 0&& days<=day[mouth]) return true;
//     if(mouth == 2&&years % 100 != 0&&years % 4 == 0||years % 400 == 0)//闰年
//     {
//         if(days<=day[2]+1) return true;
//         else{
//             return false;
//         }
//     }else{
//         days<=day[2]?true:false;
//     }
//     return false;
// }
//修补：以上考虑了 所有 正确 发现 需要 考虑 之内
//考虑错误的话  <=0  >12 
//
bool check_Vaild(int data)//检测日期合法性
{
    //分别年月日合法
    int years = data / 10000;
    int mouth = data / 100 % 100;
    int days = data % 100;
    if(mouth == 0||mouth>12) return false;
    if(!days) return false;//等于0
    if(mouth != 2 && days>day[mouth]) return false;
    if(mouth == 2)//闰年
    {
        int leap  = years % 100 != 0&&years % 4 == 0||years % 400 == 0;
        //days > (28 + leap) ?return false:return true;     都没有返回...你写你妹的
        if(days > 28 + leap) return false; 
    }
    return true;//所有 错误情况 考虑完 只能返回正确
}
int main()
{
    cin>>data1>>data2;
    for(int i = 1000;i<10000;i++)
    {

        int x = i;
        int data = i;
        for(int j = 0;j<4;j++)
        {
            data = data * 10 + x % 10 ,x /= 10;//产生回文数
        }
        if(data1<=data&&data2>=data)//范围合法
        {
            if(check_Vaild(data)) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}