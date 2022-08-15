#include <iostream>

using namespace std;

const int M = 20010;
const int N = 40;
int m, n;
int v[N];
int f[N][M];

int main() {
    
    cin >> m >> n;
    
    for(int i = 1; i <= n; i++)  cin >> v[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i]);
        }
    }
    cout << m - f[n][m] << endl;
    return 0;
    
}