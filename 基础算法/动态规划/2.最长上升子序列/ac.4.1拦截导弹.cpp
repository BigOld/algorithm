#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], f[N], g[N];
int n;

int main() {
    
    int res = 0;
    
    while(cin >> a[n]) n++;
    
    for(int i = 0; i < n; i++) {
        f[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    
    int len = 0;
    for(int i = 0; i < n; i++){
        int l = 0, r = len;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(g[mid] >= a[i]) r = mid - 1;
            else l = mid;
        }
        g[l + 1] = a[i];
        len = max(len, l + 1);
    }
  
    
    cout << len << endl;
    
    return 0;
    
}
