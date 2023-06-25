#include<bits/stdc++.h>

using namespace std;

int t;

int rs,rh;
int n,m;
//int red[11],yellow[11]; // red[i] = j i个坐标距离 j 且坐标进入得分点
int cacl(int x,int y)
{
    return x * x + y * y;
}

int midFind(vector<int> v1,int target)
{
    int l = -1,r = v1.size();
    while(l + 1 != r)
    {
        int mid = (l + r) >>1;
        if(v1[mid]<target) l = mid;
        else{
            r = mid;
        }
    }
    return l + 1;
}
int main()
{
    scanf("%d",&t);
    int tem = t;

    while(tem--)
    {
        vector<int> red,yellow;
        int minRed = 1e9,minYellow = 1e9;//最短距离
        int rs,rh;
        scanf("%d %d",&rs,&rh);
        int standR = (rs + rh) * (rs + rh);
        
        scanf("%d",&n);

        for(int i = 0,j = 0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            int temR = cacl(x,y);
            
            if(temR<=standR)
            {
                red.push_back(temR);
                
            }
            if(temR<minRed)
            {
                minRed = temR;
            }

        }
        scanf("%d",&m);
        for(int i = 0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            int temR = cacl(x,y);
            if(temR <= standR)
            {
                yellow.push_back(temR);
            }
            if(temR<minYellow)
            {
                minYellow = temR;
            }
        }
        int cntRed = 0,cntYellow = 0;
        if(minRed < minYellow)
        {
            sort(red.begin(),red.end());
            cntRed = midFind(red,minYellow);
            
        }else if(minYellow < minRed)
        {
            sort(yellow.begin(),yellow.end());
            cntYellow = midFind(yellow,minRed);

        }else if( minYellow == minRed)
        {
            sort(red.begin(),red.end());
            sort(yellow.begin(),yellow.end());
            cntRed = midFind(red,minYellow);
            cntYellow = midFind(yellow,minRed);

        }
        printf("Case #%d: %d %d\n",t- tem,cntRed,cntYellow);
    }

    return 0;
}