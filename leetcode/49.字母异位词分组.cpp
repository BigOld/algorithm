#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string> > res;

        for(auto &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        for(auto i = mp.begin(); i != mp.end(); i++) {
            res.push_back(i->second);
        }
        return res;
    }
};