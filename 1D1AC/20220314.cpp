#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, m, r; cin >> n >> m >> r;
    vector<int> R(r);
    vector<vector<int>> d(n+1, vector<int>(n+1, 100000007));
    rep(i, 0, r) cin >> R[i];
    rep(i, 1, n+1) d[i][i] = 0;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    rep(k, 1, n+1){
        rep(i, 1, n+1){
            rep(j, 1, n+1) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }
    sort(R.begin(), R.end());
    int ans = 100000007;
    do{
        int td = 0;
        rep(i, 0, r-1) td += d[R[i]][R[i+1]];
        ans = min(ans, td);
    }while(next_permutation(R.begin(), R.end()));
    cout << ans << endl;
    
}