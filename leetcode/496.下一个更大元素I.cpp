#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int>map;
        st.push(0);

        for(int i = 1; i < nums2.size(); i++) {
            if(nums2[i] <= nums2[st.top()]) st.push(i);
            else {
                // cout << nums2[i] << endl;
                while(!st.empty() && nums2[i] > nums2[st.top()]) {
                    map[nums2[st.top()]] = nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int i = 0; i < nums1.size(); i++) {
            if(map.find(nums1[i]) != map.end()) res[i] = map[nums1[i]];
        }
        return res;
    }
};