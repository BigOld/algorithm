#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;
int n;
int f[N * 2][N][N];
int w[N][N];

int main() {
    
    cin >> n;
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c) w[a][b] = c;
    
    for(int k = 2; k <= n + n; k++) 
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){
                    int t = w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];
                    int& x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
    
    cout << f[n + n][n][n];
    return 0;
}

// 处理一个点的值不能重复取
// k = i1 + j1 = i2 + j2 两个路线同时走，所以等式成立
// 因为只有在 两个横纵坐标相等的情况下，才有可能重复，这是比较 i1 == i2 就可知道是不是重复的点