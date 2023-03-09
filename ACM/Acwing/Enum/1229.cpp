// #include<bits/stdc++.h>

// using namespace std;
// // string data;
// // int data0[6];
// //枚举法
// //产生 1960 ----2059 
// //判断合法  合法则 继续 判断  年月日  月 日 年  日 月 年 分别在不在里面？
// //如何继续判断？ 19 * 100 20 * 100  + aa /  bb   /cc 是否相等？
// //aabbcc == 合法日期  输出 
// int main()
// {
//     // cin>>data;
//     // for(int i = 0,j = 0;i<data.length();i++)
//     // {
//     //     if(data[i]>='0'&&data[i]<='9')
//     //     {
//     //         data0[j++] = data[i]-'0';
//     //     }
//     // }//出来 02 / 03 /04 数字值
    
//     return 0;
// }

//枚举产生1960 -- 2056
//scanf有格式的 保存输入的数字
//判断日期合法
//合法后 与 给的aabbcc进行比较判断
//ok则输出  在1960 --2059 之中

#include<bits/stdc++.h>

using namespace std;
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check_Valid(int year,int mouth,int day)
{
    if(mouth<=0||mouth>12) return false;//月
    if(!day) return false;//日
    if(mouth != 2&&day > days[mouth]) return false;//日
    if(mouth == 2)//闰年二月
    {
        int leap = year % 4 == 0&&year % 100 != 0||year % 400 == 0;//闰年 多一天 加到下面28里面
        if(day>28 + leap) return false;
    }
    return true;
}
int a,b,c;

int main()
{
    scanf("%d/%d/%d",&a,&b,&c);
    for(int data = 19600101;data<=20591231;data++)
    {
        int year = data / 10000,mouth = data / 100 % 100,day = data % 100;//年月日 等会  会与 aabbcc比较
        if(check_Valid(year,mouth,day))
        {
            if(a == year % 100 &&b == mouth && c == day||      //年/月/日
                a == mouth&& b == day && c == year % 100||                                        //月/日/年
                a == day&&b == mouth&& c == year % 100                                        //日/月/年
            )
            {
                printf("%d-%-02d-%-02d\n",year,mouth,day);//负号代表后面补0
                //printf("%d-%02d-%02d\n",year,mouth,day);//对应 那么 输出
            }
        }
    }
    return 0;
}