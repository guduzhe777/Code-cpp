// //对一个十进制数的各位数字做一次平方和，称作一次迭代。
// //如果一个十进制数能通过若干次迭代得到 1，就称该数为幸福数。
// //显然，在一个幸福数迭代到 1 的过程中经过的数字都是幸福数
// //它们的幸福是依附于初始数字.
// //一个特立独行的幸福数，是在一个有限的区间内不依附于任何其它数字的；
// ///其独立性就是依附于它的的幸福数的个数
// //素数，则其独立性加倍
// //其它数字虽然其实也依附于其它幸福数，但因为那些数字不在给定区间 [10, 40] 内，
// //所以它们在给定区间内是特立独行的幸福数。
// //区间内的特立独行。
#include <bits/stdc++.h>
using namespace std;
int l, r; //左右界限
//从后向前遍历
//迭代函数：
using PII = pair<int, int>;
vector<PII> real_Bles;   //真正特立独行 幸福数 与 独立性
vector<int> adhere_Bles; //依附于某个数字的 幸福集合
const int N = 1e4 + 10;
bool num[N]; //数字 是否幸福数
bool prime[N];
int get_change(int num)
{
    int sum = 0;
    while (num)
    {
        int tem = num % 10;
        sum += tem * tem;
        num /= 10;
    }
    return sum; //
}
void obs()
{
    for (int i = 2; i <= N - 1; i++)
    {
        if (!prime[i]) //素数是0
        {
            for (int j = i + i; j <= N - 1; j += i)
            {
                prime[j] = true; //是合数
            }
        }
    }
}
bool isprime(int num)
{
    return !prime[num]; //返回1 这个数字 是素数
}
int main()
{
    cin >> l >> r;
    obs();

    while (r >= l) //默认不是幸福数 才是特里独行
    {
        if(num[r])
        {
            r--;//如果是幸福数 那么下一个；
        }
        int sum = r; //处理r这个数字
        while (sum != 1)
        {
            sum = get_change(sum);
            //先看这个数字是否出现过
            vector<int>::iterator it = find(adhere_Bles.begin(), adhere_Bles.end(), sum); //查看这个数字是否在之前出现过
            if (it != adhere_Bles.end())
            {
                r--;
                adhere_Bles.clear(); //依附数字r 的 数字全部删
                break;               //进行下一个数字
            }

            adhere_Bles.push_back(sum); //将依附的数们保存
            if (sum == 1)               //发现幸福数
            {
                int cnt = adhere_Bles.size();
                if (isprime(r))
                {
                    cnt *= 2; //素数乘以2
                }
                real_Bles.push_back({r, cnt}); //保存数字r  与  独立性cnt
                while (!adhere_Bles.empty())   //不空全部去除
                {
                    int tem = adhere_Bles.back();
                    adhere_Bles.pop_back();
                    num[tem] = 1; //是依附幸福数F
                }
                r--; //弄完了搞下一个数字
            }
        }
    }
    if(l<=1)
    {
        real_Bles.push_back({1,1});
    }
    if (real_Bles.empty())
    {
        printf("SAD\n");
    }
    else
    {
        for (vector<PII>::iterator it = real_Bles.end() - 1; it != real_Bles.begin() - 1; it--)
        {
            cout << it->first << " " << it->second << endl;
        }
    }

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int a, b; 
// unordered_map<int, int> mp;
// unordered_set<int> ck;
// int check(int x) {
// 	int now = x, cnt = 1;
// 	unordered_set<int> st;
// 	while(x != 1) {
// 		if(mp.count(x)) {
// 			int n = mp[x];
// 			mp.erase(x);
// 			return n + cnt;
// 		}
// 		if(st.count(x)) return -1;
// 		if(x != now) st.insert(x), ++cnt,ck.insert(x);
// 		int mid = 0;
// 		while(x) {
// 			mid += (x % 10) * (x % 10);
// 			x /= 10;
// 		}
// 		x = mid;
// 	}
// 	return cnt;
// }
// bool is_prime(int x) {
// 	if(x == 2 || x == 3) return true;
// 	if((x + 1) % 6 && (x - 1) % 6 || x < 2) return false;
// 	for(int i = 2; i <= sqrt(x); ++i) if(!(x % i)) return false;
// 	return true;
// }
// int main() {
// 	cin >> a >> b;
// 	for(int i = a; i <= b; ++i) {
// 		int x = check(i);
// 		if(x != -1) mp[i] = x;
// 	}
// 	for(int i = a; i <= b; ++i) {
// 		if(!mp.count(i) || ck.count(i)) continue;
// 		if(is_prime(i)) mp[i] *= 2;
// 		cout << i << " " << mp[i] << endl;
// 	}
// 	if(!mp.size()) cout << "SAD"; 
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int a, b; 
// unordered_map<int, int> mp;
// unordered_set<int> ck;
// int check(int x) {
// 	int now = x, cnt = 1;
// 	unordered_set<int> st;
// 	while(x != 1) {
// 		if(mp.count(x)) {
// 			int n = mp[x];
// 			mp.erase(x);
// 			return n + cnt;
// 		}
// 		if(st.count(x)) return -1;
// 		if(x != now) st.insert(x), ++cnt,ck.insert(x);
// 		int mid = 0;
// 		while(x) {
// 			mid += (x % 10) * (x % 10);
// 			x /= 10;
// 		}
// 		x = mid;
// 	}
// 	return cnt;
// }
// bool is_prime(int x) {
// 	if(x == 2 || x == 3) return true;
// 	if((x + 1) % 6 && (x - 1) % 6 || x < 2) return false;
// 	for(int i = 2; i <= sqrt(x); ++i) if(!(x % i)) return false;
// 	return true;
// }
// int main() {
// 	cin >> a >> b;
// 	for(int i = a; i <= b; ++i) {
// 		int x = check(i);
// 		if(x != -1) mp[i] = x;
// 	}
// 	for(int i = a; i <= b; ++i) {
// 		if(!mp.count(i) || ck.count(i)) continue;
// 		if(is_prime(i)) mp[i] *= 2;
// 		cout << i << " " << mp[i] << endl;
// 	}
// 	if(!mp.size()) cout << "SAD"; 
//     return 0;
// }
