#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n + 10];
        int res = 0;

        for(int i = 0; i < n; i++){
            f[i] = nums[i];
            for(int j = 0; j < i - 1; j++) {
                f[i] = max(f[i], f[j] + nums[i]);
            }
            res = max(res, f[i]);
        }
        return res;
    }
};

// 最大上升子序列 dp easy