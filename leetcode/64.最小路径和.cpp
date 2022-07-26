#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector< int > >& grid) {
        int m = grid.size() ; 
        int n = grid[0].size();
        vector<vector< int > > f(m + 10, vector<int>(n + 10, 0));
        f[1][1] = grid[0][0];
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                if(i == 1 && j != 1){
                    f[i][j] = f[i][j - 1] + grid[i - 1][j - 1];
                }else if(i != 1 && j == 1){
                    f[i][j] = f[i - 1][j] + grid[i - 1][j - 1];
                }else if(i != 1 && j != 1) {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
                }
            }

        return f[m][n];
    }
};