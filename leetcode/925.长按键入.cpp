#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while(i < name.size() && j < typed.size()) {
            if(name[i] == typed[j]) {
                i++; j++;
            }else{
                while(j < typed.size() && j > 0 && typed[j] == typed[j - 1]) j++;
                if(name[i] != typed[j]) break;
            }
            // cout << i << 'q' << j << endl;
        }
        
        if(i < name.size()) {
            return false;
        }
        while(j < typed.size()) {
            if(typed[j] == typed[j - 1]) j++;
            else return false;
        }
        return true;
    }
};