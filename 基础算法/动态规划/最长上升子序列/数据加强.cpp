#include <iostream>

using namespace std;

const int N = 100010;
int a[N], p[N];


int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int len = 0;
    
    for(int i = 0; i < n; i++) {
        
        int l = 0, r = len;
        
        while(l < r) { // 二分
            int mid = (l + r + 1) >> 1;
            if(p[mid] >= a[i]) r = mid - 1;
            else l = mid;
        }
        p[l + 1] = a[i];
        len = max(len, l + 1);
    }
    cout << len << endl;
    return 0;

}

// 各个子序列最后一个值是单调递增的，若 长度为5的子序列 最后一个值为 a ,6的子序列最后一个值为 b ,则 a < b;
// 所以维护这样一个单调数组，利用二分来查找 小于当前值的最大值，放到其后面，来优化这个数组