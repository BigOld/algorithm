#include<iostream>

using namespace std;

const int N = 110;
int f[N][N], s[N][N];
int t, a, b;

int main() {
  cin >> t;
  while(t--) {
    cin >> a >> b;
    for(int i = 1; i <= a; i++)
      for(int j = 1; j <= b; j++)
        cin >> s[i][j];
    
    for(int i = 1; i <= a; i++)
      for(int j = 1; j <= b; j++)
        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + s[i][j];
    
    cout << f[a][b] << endl;
  }
}