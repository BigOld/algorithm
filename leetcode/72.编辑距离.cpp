#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector< int > >f(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) f[i][0] = i;  //全删除
        for(int i = 0; i <= m; i++) f[0][i] = i;  //全插入

        for(int i = 1; i <= n; i++ ){
            for(int j = 1; j <= m; j++) {
                f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }
        return f[n][m];
    }
};