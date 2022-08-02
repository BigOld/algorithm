#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int n, m;
int a[N], f[N];

int main () {
    
    cin >> n;
    while(n--) {
        cin >> m;
        int res = 1;
        for(int i = 1; i <= m; i++) cin >> a[i];
        
        for(int i = 1; i <= m; i++) {
            f[i] = 1;
            for(int j = 1; j < i; j++){
                if(a[j] > a[i]){
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            res = max(res, f[i]);
        }
        for(int i = m; i >= 1; i--) {
            f[i] = 1;
            for(int j = m; j > i; j--){
                if(a[j] > a[i]){
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            res = max(res, f[i]);
        }
        cout << res << endl;
    }
    return 0;
}

// 两边最长上升