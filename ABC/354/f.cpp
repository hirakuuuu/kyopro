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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];
        vector<int> dp(n+1, IINF), dp_(n+1, IINF);
        vector<int> lis(n), rev(n);
        int l = 0;
        rep(i, 0, n){
            int pos = lower_bound(dp.begin(), dp.end(), a[i])-dp.begin();
            lis[i] = pos;
            dp[pos] = a[i];
            chmax(l, pos+1);
        }
        rrep(i, n-1, 0){
            int pos = lower_bound(dp_.begin(), dp_.end(), -a[i])-dp_.begin();
            rev[i] = pos;
            dp_[pos] = -a[i];
        }
        set<int> ans;
        rep(i, 0, n){
            if(lis[i]+rev[i]+1 == l) ans.insert(i+1);
        }
        cout << ans.size() << endl;
        for(auto aa: ans){
            cout << aa << ' ';
        }
        cout << endl;

    }
    return 0;
}