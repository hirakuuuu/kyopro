#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, x, y; cin >> n >> x >> y;
    x--, y--;
    vector<vector<int>> dist(n, vector<int>(n));
    vector<int> ans(n);
    rep(i, 0, n){
        rep(j, i+1, n){
            dist[i][j] = min(j-i, abs(x-i)+1+abs(y-j));
            ans[dist[i][j]]++;
        }
    }

    rep(i, 1, n){
        cout << ans[i] << endl;
    }
    
    return 0;
}