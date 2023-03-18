//亲密程度  w  与  距离感成反比 s  w = 1/s;
//距离感是单向的。  小蓝对小红患了单相思
//从小蓝的眼中看去，他和小红之间的距离为 1，只差一层窗户纸；
//她和小蓝之间的距离为 108000
//距离感在认识的人之间是可传递的。
//例如小绿觉得自己跟小蓝之间的距离为 2，则即使小绿并不直接认识小红，我们也默认小绿早晚会认识小红，
//小绿会觉得自己跟小红之间的距离为 1+2=3

//或者他通过其他人也能认识小红，但通过不同渠道推导出来的距离感不一样，该怎么算呢？
//小绿对小红的距离感定义为所有推导出来的距离感的最小值。
//女人缘：一个人的异性缘不是由最喜欢他/她的那个异性决定的，而是由对他/她最无感的那个异性决定的。
//我们记一个人 i 在一个异性 j 眼中的距离感为 D ij ：：i  j 二维数组 保存二者距离感
//将 i 的“异性缘”定义为 1/max j∈S(i)? {D ij? } 异性缘最大 max j∈S(i)? {D ij? } 最小
//给定的一批人与人之间的距离感中分别找出两个性别中的“大众情人”。
// N（≤500），为总人数。
//
 //性别 K 朋友1:距离1 朋友2:距离2 …… 朋友K:距离K
//输入 N 共N行  i行 对应 编号i   和 i 有关系的人 距离  给二维数组
//如何赋值：
//小绿对小红的距离感定义为所有推导出来的距离感的最小值。
//min(st[i,j],dis) 
//寻找男性 女性  性别 标记： si[i] i 1为男  0为女
//在男 女 中寻找最大距离//他/她最无感的那个异性决定的
//对于 每个i来说 凡是同性距离感无限小  寻找 距离感最大的人 
// //性别 K 朋友1:距离1 朋友2:距离2 …… 朋友K:距离K::getline();
//处理字符串
//得到二维数组关系
////对同性 赋值 最小 
////在二维数组中 寻找最大的 保存(pair保存可以 i,max0) 然后 与其他比较最小的
////6
//F 1 4:1
//F 2 1:3 4:10
//F 2 4:2 2:2
//M 2 5:1 3:2
//M 2 2:2 6:2
//M 2 3:1 2:5

#include<bits/stdc++.h>

using namespace std;
const int N = 510;
int st[N][N];
int n;
//距离全部读入
//然后再次更新
// 寻找二维数组 中 i j 异性的最大距离 再找 其中的最小值
// 输入 i  j 的最小关系
//所以默认无穷大  更新 i j最小距离
// 尽管  无穷大会存在  but  我们找 最大的最小  所以 会自动省略
//输入
//保存  性别  关系人数  读入距离
// 寻找 异性的 最大距离 保存   对最大距离 寻找最小距离
//输出  i  
bool sex[N];// sex[i] = 1 编号i  为男 
int dis[N];//dp[i]存储 i 和异性的最大距离 
int main()
{
	
    cin>>n;
    
    for(int i = 0;i<=n;i++)
    {
    	for(int j = 0;j<=n;j++)
    	{
    		if(i == j) st[i][j] = 0;	//自己和自己距离 0  
    		else{	
    			st[i][j] = 10e8;		//和别人距离 无穷大 等待寻找最大的最小  
			}
		}
	}
    for(int i = 1;i<=n;i++)  //编号i   i与 其他人的关系 
    {
        //string s;
        //getline(cin,s);//一个一个读入不要着急呀
        char ch;
        int cnt,peo,dis;//关系数  某个人  距离
		scanf(" %c %d",&ch,&cnt);
		if(ch == 'M')  sex[i] = 1;
		else{
			sex[i] = 0;
		}
		
		for(int j = 0;j<cnt;j++)//关系数 
		{
			int a,b;
			scanf("%d:%d",&a,&b); 
			st[i][a] = b;//i 和 a 距离b 
		}
    }
    //更新 和别人的 真正距离
	for(int k = 1;k<=n;k++) 
	{
		for(int i = 1;i<=n;i++) //i ,j 真正的距离  
		{
			for(int j = 1;j<=n;j++)	//你和 k  k和  j 距离们的 最小值 
			{
				st[i][j] = min(st[i][j],st[i][k] + st[k][j]);
			}
		}
	} 
	//得到真正距离后
	//寻找 和异性的最大距离
	
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(sex[i] != sex[j]){
				dis[i] = max(dis[i],st[j][i]); //找出性别不同 的最大距离 
			}
			//性别不同   
			
		 } 
	 } 
	 //找出 最大距离的最小距离
	 int d1 = 10e8,d0 = 10e8;//男女 之间的 最小距离 
	 for(int i = 1;i<=n;i++)
	 {
	 	if(sex[i]) d1 = min(d1,dis[i]);  //男性的 最大距离 中最小距离 
	 	else{
	 		d0 = min(d0,dis[i]);
		 }
	  } 
	  vector<int> ma,fma; //男4 女3
	  for(int i = 1;i<=n;i++)
	  {
	  	if(dis[i] == d1&&sex[i] == 1) ma.push_back(i);
	  	
	  }
	  for(int i = 1;i<=n;i++)
	  {
	  	if(dis[i] == d0&&sex[i] == 0) fma.push_back(i);
	  }
	  printf("%d",fma[0]);
	  for(int i = 1;i<fma.size();i++)
	  {
	  	printf(" %d",fma[i]);
	  }
	  printf("\n%d",ma[0]);
	  for(int i = 1;i<ma.size();i++)
	  {
	  	printf(" %d",ma[i]);
	  }
	  
    return 0;
}

