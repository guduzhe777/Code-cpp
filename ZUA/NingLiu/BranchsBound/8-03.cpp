#include<bits/stdc++.h>
using namespace std;

class Assignment {
private:
    struct Node {
        int person; // 当前分配的人员编号
        int cost; // 当前的费用
        vector<int> assignment; // 当前的任务分配情况
    };

    struct CompareNode {
        bool operator()(const Node& a, const Node& b) {
            return a.cost > b.cost; // 按费用升序排列，用于小顶堆
        }
    };

    vector<vector<int>> cost_Matrix;
    vector<int> assignment;
    int n;
    int minCost;

public:
    Assignment(const vector<vector<int>>& costMatrix) : cost_Matrix(costMatrix), n(costMatrix.size()), minCost(numeric_limits<int>::max()) {}

    vector<int> solve() {
        priority_queue<Node, vector<Node>, CompareNode> pq;
        Node initialNode{0, 0, vector<int>(n, -1)}; // 初始节点，人员编号为0，费用为0，任务分配情况为空
        pq.push(initialNode);

        while (!pq.empty()) {
            Node curNode = pq.top();
            pq.pop();

            int curPerson = curNode.person;
            int curCost = curNode.cost;
            vector<int> curAssignment = curNode.assignment;

            if (curPerson == n) {
                if (curCost < minCost) {
                    minCost = curCost;
                    assignment = curAssignment;
                }
                continue;
            }

            for (int task = 0; task < n; task++) {
                if (curAssignment[task] == -1) {
                    vector<int> newAssignment = curAssignment;
                    newAssignment[task] = curPerson;
                    int newCost = curCost + cost_Matrix[curPerson][task];

                    Node newNode{curPerson + 1, newCost, newAssignment};
                    pq.push(newNode);
                }
            }
        }

        return assignment;
    }
};

int main() {
    int n;
    
    cin >> n;

    vector<vector<int>> cost_Matrix(n, vector<int>(n));
    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost_Matrix[i][j];
        }
    }

    Assignment assignment(cost_Matrix);
    vector<int> optimalAssignment = assignment.solve();
    for (int i = 0; i < n; i++) {
        cout << "任务 " << i + 1 << " -> 人 " << (optimalAssignment[i] + 1) << endl;
    }
    int sum = 0;
    for (int i = 0,j = 0; i < n; i++,j++) {
        sum += cost_Matrix[j][optimalAssignment[i]];
    }
    cout<<"最小花费："<<sum<<endl;
    return 0;
}