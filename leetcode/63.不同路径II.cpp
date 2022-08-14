#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector< int > >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector< int > > f(m + 10, vector<int>(n + 10, 0));


        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) { // 不能写进 if 里面，因为如果被阻挡后面就不可能到达，只能向右 向下走
            f[i][0] = 1;
        }
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            f[0][j] = 1;
        }


        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 0){
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};