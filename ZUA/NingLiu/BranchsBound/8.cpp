#include<bits/stdc++.h>

using namespace std;


int n;


//可能价值 作为节点优先扩展的条件 优先级排序
//bestp 最大价值 提前更新 用于右节点的up（可能最大价值）的比较
//因为贪心 所以 bound(1)>bound(2) 1 i较于i+1 性价比最高
//预先处理 性价比最高先 +导致尽最大能力剪枝
//bestp 可以认为是 到每一个节点 最大价值  
//up=bestp 是右子树 叶子节点 n+1 与 n层向右 up = bestp 这个节点可能为最大价值
//所以右子树剪枝  up >= bestp 等于也可能是最大价值节点
//树模型 设置约束条件  限界函数
//  n皇后：与上面打不打架
//
//单源最短路径  将图展开为树 加以约束
//旅行售货员    以 到当前花费 + 剩余节点的全部出边的最小出边花费 即最小花费 排序 rcost:1-n最大价值 每一个节点(i)后 rcost - m[i] 为剩余节点最小花费
//              一个数值为 选择某个节点  第一个节点一定为1 所以有图https://zhuanlan.zhihu.com/p/141680086
//自己排自己的 分支限界
//界为： curCost + allMinCost 这样选择的 最小花费还是大于已知的最小花费  则没必要扩展
//
//01背包  界为 curP + allMaxP 这样选择下 最大的价值还是小于等于已知的最大节点 则不要扩展
int main()
{
    cin>>n;
    vector<vector<int> > c(n+1,vector<int>(n+1,0));


    return 0;
}