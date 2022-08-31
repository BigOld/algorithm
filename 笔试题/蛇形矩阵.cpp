#include <iostream>

using namespace std;
int res[110][110];
int main() {
    int n, m;
    // 定义四个方向
    int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
    
    cin >> n >> m;
    for(int x = 0, y = 0,d = 0, k = 1; k <= m * n; k++) {
        res[x][y] = k;
        // 先预存一下，方便后面修改
        int a = x + dx[d], b = y + dy[d];
        // 超出之后通过取模来改变方向
        if(a < 0 || a >= n || b < 0 || b >= m || res[a][b]){
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a;
        y = b;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// https://www.acwing.com/problem/content/description/758/