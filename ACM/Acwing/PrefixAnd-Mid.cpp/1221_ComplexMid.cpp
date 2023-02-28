#include<bits/stdc++.h>

using namespace std;
const int N = 5e7 ;//存储c * c + d * d
struct Sum{
    int s;
    int c;
    int d;
    bool operator< (const Sum &t)const
    {
        if(s != t.s) return s<t.s;//返回true s<t.s 把对应结构体放在前面 目的 结构体有序 等待二分查找
        if(c != t.c) return c<t.c;//保证输出有字典序
        if(d != t.d) return d<t.d;//为什么？ 在s相同情况下 c小的放在前面  更快的访问到
        return true;//都一样情况？ 因为规定输入c<d 不存在都一样
    }
}sum[N];//存储 c * c  + d * d

int n;//保存 需要组成的数
int m;//保存 保存的数组数量
int t;//得到 开根n - a^2 - b^2值进行寻找
int main()
{
    scanf("%d",&n);
    for(int c = 0;c * c<= n;c++)
        for(int d = c;c * c + d * d<=n;d++)
            sum[m++] = {c * c + d * d,c,d};
    sort(sum,sum+m);//依靠 重载运算符排序
    for(int a = 0;a * a<=n;a++)
    {
        for(int b = 0;b * b + a * a<=n;b++)
        {
            int res = n- a * a - b * b;
            
            int l = -1,r = m;
            while(l + 1!=r)
            {
                int mid = (r - l)/2+l;
                if(sum[mid].s>=res) r = mid;
                else l = mid;

            }
            //二分后
            if(res == sum[r].s)
            {
                printf("%d %d %d %d",a,b,sum[r].c,sum[r].d);
                return 0;
            }

        }
    }
    return 0;
}