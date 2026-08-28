#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> b(k);
    vector<int> l(k), s(k);
    vector<vector<int>> cnt(n, vector<int>(30));
    rep(i, 0, k){
        cin >> l[i] >> s[i];
        b[i].resize(l[i]);
        rep(j, 0, l[i]){
            cin >> b[i][j]; b[i][j]--;
            rep(ii, 0, 30){
                if(s[i]>>ii&1) cnt[b[i][j]][ii]++;
            }
        }
    }
    mint ans = 0;
    rep(i, 0, n){
        rep(j, 0, 30){
            if(cnt[i][j] == 0) continue;
            // cout << i << ' ' << j << endl;
            ans += mint(1<<j)/2;
        }
    }
    cout << ans.val() << endl;
    return 0;
}