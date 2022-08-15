#include <iostream>

using namespace std;

const int N = 1010;
const int M = 110;
int n, m;
int f[M][N];
int t[M], v[M];

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) cin >> t[i] >> v[i];
    
    for(int i = 1; i <= m; i++) { // 前 i 个商品
        for(int j = 1; j <= n; j++) {  // 时间为 j
            f[i][j] = f[i - 1][j];
            if(j >= t[i])
                f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + v[i]);
        }
    }
    
    cout << f[m][n] << endl;
    return 0;
    
}