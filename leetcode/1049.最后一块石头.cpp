#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> f(3010, 0);

        int sum = 0;

        for(int i = 0; i < stones.size(); i++) sum += stones[i];

        int target = sum / 2;

        for(int i = 0; i < stones.size(); i++) {
            for(int j = target; j >= stones[i]; j--){
                f[j] = max(f[j], f[j - stones[i]] + stones[i]);
            }
        }

        return sum - f[target] * 2;

    }
};

// 可以转换为01背包问题 其实也是挑一定的石头并分为两波，最后输出结果
// 求left， target = sum / 2, 用right - left 即为结果