#include <iostream>

using namespace std;

const int N = 10010;
int s[N], v[N], w[N];
int n, m;
int main() {
    
    int f[N][N];
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= s[i] & k * v[i] <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
    
}


int main2() {
    int f[N];
    int t = 0;
    cin >> n >> m;
    
    while(n--) { // 将多重背包一个一个拆出来
        int a, b, c;
        cin >> a >> b >> c;
        while(c--) {
            v[++t] = a;
            w[t] = b;
        }
    }
    
    for(int i = 1; i <= t; i ++) {
        for(int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
            
    cout << f[m] << endl;
    
    return 0;
    
}