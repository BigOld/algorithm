#include <iostream>
#include <vector>

using namespace std;
// 法一，单纯的二分
class Solution {
public:
    bool searchMatrix(vector<vector< int > >& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int p = 0, q = 0;
        for(; p < m; p++) {
            if(matrix[p][n - 1] > target) break;
            else if(matrix[p][n - 1] == target) return true;
        }
        for(; q < n; q++) {
            if(matrix[m - 1][q] > target) break;
            else if(matrix[m - 1][q] == target) return true;
        }
        for(int i = p; i < m; i++) {
            int left = q, right = n - 1;
            while(left < right) {
                int mid = (left + right) / 2;
                if (matrix[i][mid] >= target) right = mid;
                else left = mid + 1;
            }
            if(matrix[i][left] == target) return true;
        }
        return false;
    }
};

// 法二：利用递增的特性：
// 如果 (x, y) > target, 说明纵向的这一列没有答案，所以去掉，执行 y--
// 否则 (x, y) < target， 说明这一行没有答案，去掉，执行 x++
class Solution1 {
public:
    bool searchMatrix(vector<vector< int > >& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;

        while(x < m && y >= 0) {
            if(matrix[x][y] > target) y--;
            else if(matrix[x][y] < target) x++;
            else return true;
        }
        return false;

    }
};