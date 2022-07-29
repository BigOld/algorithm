#include <iostream>
#include <algorithm>

using namespace std;

const int N = 60;
int n, m;
int f[N * 2][N][N];
int w[N][N];

int main() {
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            cin >> w[i][j];
    for(int k = 2; k <= n + m; k ++) 
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++) {
                
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m){
                    int t = w[i1][j1];
                    
                    if(i1 != i2) t += w[i2][j2];
                    
                    int& x = f[k][i1][i2];
                    
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
    cout << f[n + m][n][n];
    return 0;
}


// 因为所有节点的权值都为非负数，那么可以证明走交点的路线永远不可能是最优解。
// 比如以交点（2，2）为例，蓝色从（3，1）绕道或者红色从（1，3）处绕道一定不会比两条路径都从（2，2）处走差。