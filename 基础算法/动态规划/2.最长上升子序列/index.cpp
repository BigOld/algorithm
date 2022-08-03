// LIS Longest Increasing Seqence

// 状态表示 所有以f[i]结尾的严格单调上升子序列

# include <iostream>
# include <algorithm> 

using namespace std;

const int N = 1010;
int f[N], a[N];

int main() {
    int n, res = 1;
    cin >> n;
    
    for(int i = 1; i <=n ;i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        f[i] = 1; // 这一句很精髓
        for(int j = 1; j < i; j++) {
            if(a[i] > a[j]) 
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    
    cout << res << endl;
    
    return 0;
}

// leetcode 300
