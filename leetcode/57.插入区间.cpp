#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector <int> > insert(vector<vector <int> >& intervals, vector<int>& newInterval) {
        vector<vector <int> > res;
        bool place = false;
        int left = newInterval[0];
        int right = newInterval[1];
        for(int i = 0; i < intervals.size(); i++) {

            vector<int> interval = intervals[i];

            if(interval[1] < left) { // 在插入区间的左边
                res.push_back(interval);
            }else if(interval[0] > right) { // 在插入区间的右边
                if(!place) {
                    res.push_back( {left, right} );
                    place = true;
                }
                res.push_back(interval);
            }else{ // 有重合，合并区间
                left = min(interval[0], left);
                right = max(interval[1], right);
            }
        }
        if(!place) {
            res.push_back( {left, right});
        }
        return res;
    }
};