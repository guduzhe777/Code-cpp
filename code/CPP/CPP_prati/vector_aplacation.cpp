#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int target,sign;

    int arr[10] ={12,10,13,14,15,20,25,26,30,56};
    vector<int>a(arr,arr+10);   //数组放到vector变形int中

    for(int i =0;i<10;i++)
    {
        cout<< a[i] <<endl;
    }
    cin >> sign >> target;
    a.insert(a.begin() + sign - 1,1,target);
    
    for(int i =0;i<11;i++)
    {
        cout<< a[i] <<endl;
    }
    return 0;
}

