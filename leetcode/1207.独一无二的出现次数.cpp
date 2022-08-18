#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[2010] = {0};
        for(int i = 0; i < arr.size(); i++) {
            hash[arr[i] + 1000]++;
        }
        bool p[1002] = {false};
        for(int i = 0; i < 2000; i++) {
            if(hash[i]){
                if(!p[hash[i]]) p[hash[i]] = true;
                else return false;
            }
        }
        return true;
    }
};