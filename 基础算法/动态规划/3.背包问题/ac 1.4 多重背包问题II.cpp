#include <iostream>
using namespace std;

const int N = 12010, M = 2010;

int f[M], v[N], w[N];
int n, m;

int main() {
    
    cin >> n >> m;
    int cnt = 0;
    while(n--) {
        int a, b, c, k = 1;
        cin >> a >> b >> c;
        while(c >= k){
            c -=k;
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            k *= 2;
        }
        if(c){
            cnt ++;
            v[cnt] = a * c;
            w[cnt] = b * c;
        }
    }
    
    for(int i = 1; i <= cnt ;i++) {
        for(int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
    
}