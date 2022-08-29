#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') count++;
        }
        int p = s.size() - 1;
        s.resize(p + 1 + count * 2);
        int q = s.size() - 1;
        while(p != q){
            if(s[p] == ' '){
                s[q--] = '0';
                s[q--] = '2';
                s[q] = '%';
            }else {
                s[q] = s[p];
            }
            p--, q--;
        }
        return s;
    }
};