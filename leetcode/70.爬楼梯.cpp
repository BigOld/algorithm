#include <iostream>
#include <vector>

using namespace std;

// 递归超时
class Solution {
public:
    int rec(int n) {
        if(n < 3) return n;
        return rec(n - 1) + rec(n - 2);
    }
    int climbStairs(int n) {
        int res = rec(n);
        return res;
    }
};

// 动归 YYDS
class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> f(n + 10, 0);
        f[1] = 1;
        f[2] = 2;
        for(int i = 3; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

