#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while(l < r) { // 二分法通过第一个数字找到左边有序数列的右边界
            int mid = (l + r + 1) >> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        int v = l;
        if(target >= nums[0]) {
            l = 0;
        }else {
            l = v + 1, r = nums.size() - 1;
        }
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[r] == target) return r; // 用 l 的数组会越界 如：[1] 0
        return -1;
    }
};