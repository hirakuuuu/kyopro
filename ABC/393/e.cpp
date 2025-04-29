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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    int mx = 1000000;
    vector<int> a(n);
    vector<int> cnt(mx+1);
    rep(i, 0, n) cin >> a[i], cnt[a[i]]++;

    vector<int> cnt_baisu(mx+1);
    rep(i, 1, mx+1){
        for(int j = i; j < mx+1; j += i){
            cnt_baisu[i] += cnt[j];
        }
    }

    vector<int> ans(mx+1);
    rep(i, 1, mx+1){
        if(cnt_baisu[i] < k) continue;
        for(int j = i; j < mx+1; j += i){
            ans[j] = i;
        }
    }

    rep(i, 0, n){
        cout << ans[a[i]] << '\n';
    }
    
    return 0;
}