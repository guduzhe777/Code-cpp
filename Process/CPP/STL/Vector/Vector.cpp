// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;
// vector<int> ans = {0,1,2,3,4,5,6};//赋值
// vector<int> ans1(5,1);
// //vector<int,int> vii; 错误的定义，vector<T>.T只能为一种类型
// //二维vector 可以
// vector<vector<int>> vii;//二维数组 
// //若要将两个有关系的信息连接在一起，
// //可以用
// using si = pair<string,int>;
// vector<si> stu;
// //多元在一起 可以利用 struct  
// struct peo{
//     int h,w,iq;
// };
// vector<peo> peo0;

// int main()
// {
//     //二元组vector
//     stu.push_back({"刘磊",11});
//     cout<<stu[0].first<<" "<<stu[0].second<<endl;

//     //多元组vector
//     //peo0.push_back({1,2,3}); 
//     peo0.push_back({0,1,0});
//     cout<<peo0[0].h<<peo0[0].w<<peo0[0].iq<<endl;

//     vii = {{1,1}};//二维vector赋值
//     ///push_back,类似赋值。放数组可以{}一同放
//     cout<<vii[0][1]<<" "<<vii[0][0]<<endl;
//     // for(vector<int>::iterator it = ans.begin();it != ans.end();it++)
//     // {
//     //     cout<<*it<<" ";
//     // }
//     // printf("\n");
//     // ans.erase(ans.begin() );       //其中的参数要是指针变量，比如begain(),end(),以及迭代器值）
//     // for(vector<int>::iterator it = ans.begin();it != ans.end();it++)
//     // {
//     //     cout<<*it<<" ";
//     // }
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
 
int main()
{
    using namespace std;
 
    vector<int> vec;
 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
 
    vector<int>::iterator it = find(vec.begin(), vec.end(), 6);//寻找6
 
    if (it != vec.end())
        cout<<*it<<endl;
    else
        cout<<"can not find"<<endl;
 
    return 0;
}