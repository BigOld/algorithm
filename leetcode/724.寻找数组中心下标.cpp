#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size();i++) sum += nums[i];
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int a = sum - nums[i];
            
            if(a % 2 == 0 && leftSum == a / 2) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};