#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];
int res; 

int main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) {
        f[i] = a[i];
        for(int j = 1; j < i ; j++) {
            if(a[i] > a[j]){
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}

// 状态标识 f[i] 变为最大值，之前是长度