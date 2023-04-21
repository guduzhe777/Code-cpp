#include <bits/stdc++.h>
using namespace std;

int n;
string s[50001];

int main() {
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++)
		getline(cin, s[i]);
	sort(s + 1, s + n + 1);
	if (s[1].substr(0, 8) != "00:00:00")
		cout << "00:00:00 - " << s[1].substr(0, 8) << endl;
	for (int i = 1; i < n; i++)
		if (s[i].substr(11, 8) != s[i + 1].substr(0, 8))
			cout << s[i].substr(11, 8) << " - " << s[i + 1].substr(0, 8) << endl;
	if (s[n].substr(11, 8) != "23:59:59")
		cout << s[n].substr(11, 8) << " - 23:59:59" << endl;
	
	return 0;
}//2


