#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int x; cin >> x;
        float u, g; cin >> u >> g;
        printf("%d && %f && %f", i+1, u, g);
        cout << "\\\\" << endl;
    }
    
    return 0;
}