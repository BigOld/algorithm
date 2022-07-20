#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int size = matrix[0].size();
        for(int j = 0; j < size; j++) {
            for(int i = 0; i < j; i++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size / 2; j++) {
                swap(matrix[i][j], matrix[i][size - 1 - j]);
            }
        }
    }
};

// 直接旋转操作比较复杂，先对角旋转在，然后再一中心的竖线为轴旋转