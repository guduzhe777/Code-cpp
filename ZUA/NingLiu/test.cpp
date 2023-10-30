#include <iostream>
#include <algorithm>
using namespace std;

template<class Type>
void ranks(Type a[], int k, int m, bool visited[]) {
    if (k == m) {
        for (int i = 0; i <= m; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i <= m; i++) {
            if (visited[i] || (i > 0 && a[i] == a[i-1] && !visited[i-1])) {
                continue; // 跳过重复的元素
            }
            visited[i] = true;
            swap(a[k], a[i]);
            ranks(a, k + 1, m, visited);
            swap(a[k], a[i]);
            visited[i] = false;
        }
    }
}

template<class Type>
inline void swap(Type &a, Type &b) {
    Type temp = a;
    a = b;
    b = temp;
}

int main() {
    char a[3] = {'a', 'b', 'b'};
    sort(a, a + 3); // 对元素进行排序
    bool visited[3] = {false};
    ranks(a, 0, 2, visited);
    return 0;
}