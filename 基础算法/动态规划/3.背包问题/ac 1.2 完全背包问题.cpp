#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N];

int main() {
    
    int f[N][N];
    int n , m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i<= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k * v[i] <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                // 这里不能写 f[i][j] = max(f[i - 1][j], f[i - 1][j - k * v[i]] + k * w[i]);
                // 因为没有保存 f[i][j]的值，如果右边的数很小就会,f[i][j] 就会又被f[i - 1][j]覆盖，会回退
            }
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
    
}


// 第一次优化
// f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....)
// f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-3*v]+2*w , .....)
// 由上两式，可得出如下递推关系： 
// f[i][j]=max(f[i,j-v]+w , f[i-1][j]) 

int main1() {

    int f[N][N];
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
    
}

// 01 背包  f[i][j] = max(f[i][j],f[i-1][j-v[i]]+w[i]); 
// 完全背包  f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
// i - 1 和 i 决定了 j 从大到小 还是 从小到大
// 因为 i - 1 需要用到上一行的结果，从小到大会将之前的结果覆盖掉（只用一维数组）所以要从大到小遍历
// 而 i 需要用到当前行的结果，所以需要从小到大

// 第二次优化

int main2(){

  int f[N];
  int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            if(j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[m] << endl;
    return 0;
}