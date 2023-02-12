#include <bits/stdc++.h>

using namespace std;

class peo
{
    float weight, tall;
    friend double operator+(const peo &a, const peo &b);
};
double operator+(const peo &a, const peo &b)
{
    return a.weight + b.weight;
}
int main()
{

    return 0;
}