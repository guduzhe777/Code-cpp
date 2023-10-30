#include <bits/stdc++.h>

#define N 1000

using namespace std;



int n, k;

int d[N][N];

int main()

{



    ios::sync_with_stdio(false);

    cin >> n >> k;

    int tem = n;
    //i为空
    for (int i = 0; i <= k; i++)

    {

        cin >> d[i][i + 1];

    }

    int cnt = 0;

    vector<int> v;

    for (int i = 0; i <= k; i++)

    {

        if (d[i][i + 1] > n) //加油过不了

        {

            cout << "No Solution" << endl;

            return 0;

        }



        if (tem - d[i][i + 1] < 0) //过不去加油再过
        {

            cnt++;

            v.push_back(i);

            tem = n;

        }

        tem -= d[i][i + 1]; //直接过

    }

    cout<<cnt << endl;

    cout<<"加油点为:";

    vector<int>::iterator it;

    for(it = v.begin();it != v.end();it++)

    {

        cout<<*it<<" ";

    }

    return 0;

}

