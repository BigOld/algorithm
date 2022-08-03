#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>f(n + 10);
        int res = 0;

        if(n == 1) return nums[0];

        for(int i = 0; i < n - 1; i++) {
            f[i] = nums[i];
            for(int j = 0; j < i - 1; j++){
                f[i] = max(f[i], f[j] + nums[i]);
            }
            res = max(res, f[i]);
        }
        
        for(int i = 1; i < n; i++) {
            f[i] = nums[i];
            for(int j = 1; j < i - 1; j++){
                f[i] = max(f[i], f[j] + nums[i]);
            }
            res = max(res, f[i]);
        }
        return res;
    }
};

// 其实就是两两遍， 这样保证首尾不会同时被算上
// 第一次是从 0 - n - 2
// 第二次是从 1 - n - 1