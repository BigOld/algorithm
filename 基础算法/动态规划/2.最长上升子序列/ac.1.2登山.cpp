#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
int a[N], f[N], g[N];
int w[N];

int main () {
    
    cin >> m;
    
    for(int i = 1; i <= m; i++) cin >> a[i];
    
    for(int i = 1; i <= m; i++) {
        f[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        
    }
    for(int i = m; i; i--) {
        g[i] = 1;
        for(int j = m; j > i; j--){
            if(a[j] < a[i]){
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }
    
    int res = 1;
    for(int i = 1; i <= m; i++) res = max(res, f[i] + g[i] - 1);
    cout << res << endl;
    
    return 0;
}

// 类似怪盗基德，但是上一个是求 向左和向右的最大值，这道题试求向左+向右的最大值，依然是两次不同方向的最长上升