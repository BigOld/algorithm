#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int>PII;
const int N = 5010;

PII q[N];
int f[N];
int n, res = 1;

int main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> q[i].first >> q[i].second;
    sort(q, q + n + 1);
    
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j < i; j++){
            if(q[i].second > q[j].second){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        res = max(res, f[i]);
    }    
    cout << res << endl;
    return 0;
}

// 画图！！！
// 按照北边的先排序，南边的作为因变量，可以转化为 最长上升子序列问题 如果要不相交一定是单调上升的
// 因为是一对值，所以用 pair
