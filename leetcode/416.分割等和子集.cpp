#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int>f(200010, 0);
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++) sum+= nums[i];
        if(sum % 2 == 1) return false;
        int target = sum / 2;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
                f[j] = max(f[j], f[j - nums[i]] + nums[i]);
            }
        }
        if (f[target] == target) return true;
        return false;
    }
};

// 可以转换为01背包问题 从中算一定的数，并且只能选一次，使结果为 target = sum / 2（容量为target）