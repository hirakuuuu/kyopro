#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int r, c, k; cin >> r >> c >> k;
    int n; cin >> n;
    vector<int> R(r), C(c);
    vector<vector<int>> candy(r);
    rep(i, 0, n){
        int cr, cc; cin >> cr >> cc;
        cr--, cc--;
        candy[cr].push_back(cc);
        R[cr]++;
        C[cc]++;
    }
    ll ans = 0;
    vector<int> cnt(n+1);
    rep(i, 0, c) cnt[C[i]]++;
    rep(i, 0, r){
        int rest = k-R[i];
        if(rest < 0) continue;
        int cnt_c = 0;
        for(auto cc: candy[i]){
            if(C[cc] == rest+1) ans++;
            else if(C[cc] == rest) cnt_c++;
        }
        ans += (ll)cnt[rest]-cnt_c;
    }
    cout << ans << endl;


    
    return 0;
}