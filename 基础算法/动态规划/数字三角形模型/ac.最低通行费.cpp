#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int w[N][N];
int f[N][N];

int main() {
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> w[i][j];
            f[i][j] = min(f[i][j - 1], f[i - 1][j]) + w[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j != 1) f[i][j] = f[i][j - 1] + w[i][j];
            else if(i != 1 && j == 1) f[i][j] = f[i - 1][j] + w[i][j];
            else f[i][j] = min(f[i][j - 1], f[i - 1][j]) + w[i][j];
        }
    cout << f[n][n] << endl;
    return 0;
    
}