#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<pii>> g(305);

int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> d(305, vector<ll>(305, (1LL<<60)));
    vector<vector<int>> e;
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
        e.push_back({a, b, c});
    }
    rep(k, 1, n+1){
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, m){
        int a = e[i][0], b = e[i][1], c = e[i][2];
        rep(k, 1, n+1){
            if(d[a][k]+d[k][b] <= c){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}