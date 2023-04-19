
 #include <bits/stdc++.h>
using namespace std;
const int N = 1e4, M = 1e5; 

int n, m, cnt, temp, pre[N + M + 1];
//n:老人总数量 m：管理边数 cnt：管理节点数 pre[i]：i的父亲 
set<string> st;   //管理节点即管理中心字符串   set好处为 count(a) 检测first a 的个数
// 管理节点字符串 
//哈希 对管理节点进行编号 
map<string, int> mp1;   //节点字符串对应的 编号
//管理节点对应编号
map<int, string> mp2;   //编号 - 管理节点
//编号对应管理节点      
vector<int> v[N + M + 1];   //
//存图v[i], i的后继 

inline void dfs(int x) {
	for (auto y : v[x]) {   //遍历 老人 直接++  dfs 遍历  管理中心 的 老人。  dfs一个图/树 得到节点个数
		if (y <= n) //y小于等于n代表老人 
			++temp;
		dfs(y); //递归 
	}
}

int main() {
	cin >> n >> m;
	cnt = n;
	for (int i = 1; i <= m; i++) {
		string s1, s2;
		int num1, num2;
		cin >> s1 >> s2;
		if (s1[0] >= '0' && s1[0] <= '9') // s1为老人编号 
			num1 = stoi(s1);
		else if (st.count(s1))//
			num1 = mp1[s1]; //得到s1 编号( s1一定有 )
		else {
			//将s1插入st中，并对s1编号，映射 
			st.insert(s1);
			num1 = ++cnt;
			mp1[s1] = cnt;
			mp2[cnt] = s1;
		}
		if (st.count(s2))
			num2 = mp1[s2];
		else {
			//将s2插入st中，并对s2编号，映射
			st.insert(s2);
			num2 = ++cnt;
			mp1[s2] = cnt;
			mp2[cnt] = s2;
		}
		//num1的父节点为num2 
		pre[num1] = num2;
		v[num2].push_back(num1);
	}
	char op;
	while (cin >> op && op != 'E') {
		if (op == 'Q') {
			string str;
			cin >> str;
			temp = 0;
			dfs(mp1[str]);
			printf("%d\n", temp);
		} else {
			int num1, num2;
			string str;
			cin >> num1 >> str;
			num2 = mp1[str];
			int fa = pre[num1];
			if (fa) 
				for (auto it = v[fa].begin(); it != v[fa].end(); ++it)
					if (*it == num1) {
						v[fa].erase(it);
						break;
					}
			v[num2].push_back(num1);
			pre[num1] = num2; 
		}
	}
	
	return 0;
} //3