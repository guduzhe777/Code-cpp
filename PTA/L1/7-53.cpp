#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		string a; getline(cin,a);
		int sum=0;
		for(int j=0;j<a.size();j++){
			sum+=a[j]-'0';
		}
		if(sum%3==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
} 

