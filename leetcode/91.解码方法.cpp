#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> f(s.size() + 10, 0);
        if (s[0] == '0') return 0;
        s = ' ' + s;
        f[0] = 1; // -1
        f[1] = 1;
        for(int i = 2; i < s.size(); i++) {
            f[i] = f[i - 1];
            if(s[i] == '0') {
                if(s[i - 1] == '1' || s[i - 1] == '2') f[i] = f[i - 2];
                else return 0;
            }else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] > '0' && s[i] <= '6')){
                f[i] = f[i - 1] + f[i - 2];
            }

        }

        return f[s.size() - 1];
    }
};