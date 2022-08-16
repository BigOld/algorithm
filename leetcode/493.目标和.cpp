#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> f(1010, 0);
        f[0] = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if(abs(target) > sum) return 0;
        if((sum + target) % 2 == 1) return 0;
        int a = (sum + target) / 2;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = a; j >= nums[i]; j--) {
                f[j] += f[j - nums[i]];
            }
        }

        return f[a];
    }
};


//  01背包问题
// 这里已经给我我们target，
// target = left - right = left - (sum - left)
// left = (sum - target) / 2
// f[j]表示的是方法数，而不是最大值了