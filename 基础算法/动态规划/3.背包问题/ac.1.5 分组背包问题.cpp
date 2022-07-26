#include <iostream>
#include <algorithm>

using namespace std;

const int N  = 110;
int f[N], v[N][N], w[N][N], s[N];

int main() {
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++ )
            cin >> v[i][j] >> w[i][j];
    }
    
    // 直接用 一维数组 来优化，j 从大到小遍历，参考 01 背包的优化
    for(int i = 1; i <= n; i++) {  // 第 i 组
        for(int j = m; j >= 1; j--) { // 体积
            for(int k = 1; k <= s[i]; k++) { // 第 i 组选第 k 个物品
                if(j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
    
}