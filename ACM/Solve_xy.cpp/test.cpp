# include<iostream>
# include<algorithm>
# include<vector>
using namespace std;

typedef long long LL;

//1.快速幂算法基本模板,计算a^b%m，对于a特别大的时候，它也无法处理，引入快速乘法 

//LL quick_mod(LL a, LL b, LL m){
//	LL res = 1;
//	while(b){
//		if(b&1)
//			res = res * a % m;
//		a = a * a % m;
//		b = b >> 1;
//	}
//	return res;
//} 


//2 快速乘法：计算a*b%m

LL quick_mul(LL a, LL b, LL m){	
	LL res = 0;
	while(b){
		if(b&1)
			res = (res + a)%m; 
		b = b>>1;
		a = (a+a)%m;
	}
	return res;
} 

//3.快速幂算法最终模板,计算a^b%m，对于a特别大的时候，调用快速乘法 

LL quick_mod(LL a, LL b, LL m){
	LL res = 1;
	while(b){
		if(b&1)
			res = quick_mul(res, a, m);
		a = quick_mul(a, a, m);
		b = b >> 1;
	}
	return res;
} 


//4 欧几里得算法求a与b的最大公约数

int gcd(int a, int b){

	return b==0?a:gcd(b,a%b);

} 

// 5 扩展欧几里得算法 ax+by = gcd(a,b)的整数解, 重点理解其数学含义 

int exgcd(int a, int b, int &x, int &y){
	
	if(b==0){
		x = 1;
		y = 0;
		return a;		
	}
	int res = exgcd(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp - (a/b)*y;
    return res;
}
 
void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

int main(){
//	cout<<quick_mul(2,10,50);
	//动态数组,STL
//	vector<int> a;
//	for(int i=0;i<100;i++){
//		a.push_back(rand()%100);
//	}
//	for(int i=0;i<a.size();i++){
//		cout<<a[i]<<endl;
//	}
//	sort(a.begin(),a.end());
//	cout<<"排序之后"<<endl;
//	for(int i=0;i<a.size();i++){
//		cout<<a[i]<<endl;
//	}
//	
	
	//C++ 引用 &
   
	int a = 15, b = 12 ,x,y;
	cout<<exgcd(a,b,x,y)<<endl;
	
	cout<<"整数解为"<<x<<" "<<y<<endl;
	

    // int p,q;
    // LL n = 1001733993063167141;
	// for(int i=3;i<n/i;i++){
	// 	if(n%i == 0)
	// 		cout<<i<<" "<<n/i<<endl;
		
	// } 

	
	return 1;
}


