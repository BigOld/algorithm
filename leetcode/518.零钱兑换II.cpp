#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 10, 0);
        f[0] = 1;
        for(int i = 0 ; i < coins.size(); i++) {
            for(int j = 0; j <= amount; j++) {
                if(j >= coins[i])
                    f[j] += f[j - coins[i]];
            }
        }

        return f[amount];
    }
};

