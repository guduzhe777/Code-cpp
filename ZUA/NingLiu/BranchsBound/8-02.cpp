#include <iostream>
#include <vector>
#include <limits>
using namespace std;

template <typename T>
class TempStg {
private:
    struct node {
        T* dat;
        node* next;
    };
    node H; // 头结点不存数据
public:
    TempStg() {
        H.next = 0;
    }
    ~TempStg() {
        node* p = H.next;
        while (p) {
            node* t = p;
            p = p->next;
            delete t->dat;
            delete t;
        }
    }
    T* newNode() {
        node* q = new node;
        q->dat = new T;
        q->next = H.next;
        H.next = q;
        return q->dat;
    }
};

class Assignment {
private:
    vector<vector<int>> cost_Matrix;
    vector<int> assignment;
    int n;
    int minCost;
    TempStg<vector<int>> tempStg;

    void backtrack(int k, int curCost, vector<int>& visited) {
        if (k == n) {
            if (curCost < minCost) {
                minCost = curCost;
                assignment = visited;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                visited[i] = k;
                curCost += cost_Matrix[k][i];

                if (curCost < minCost) {
                    backtrack(k + 1, curCost, visited);
                }

                visited[i] = -1;
                curCost -= cost_Matrix[k][i];
            }
        }
    }

public:
    Assignment(const vector<vector<int>>& costMatrix) : cost_Matrix(costMatrix), n(costMatrix.size()), minCost(numeric_limits<int>::max()) {}

    vector<int> solve() {
        vector<int> visited(n, -1);
        backtrack(0, 0, visited);
        return assignment;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
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

    cout << "Optimal assignment of tasks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Person " << i + 1 << " -> Task " << (optimalAssignment[i] + 1) << endl;
    }
    int sum = 0;
    for (int i = 0,j=0; i < n; i++,j++) {
        sum += cost_Matrix[j][optimalAssignment[i]]; //j任务给 
    }
    cout<<"最小消耗时间:"<<sum<<endl;
    return 0;
}