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

// 問題
// https://atcoder.jp/contests/abc207/tasks/abc207_c

int main(){
    int n; cin >> n;
    vector<pair<double, double>> lr(n);
    rep(i, 0, n){
        int t;
        double l, r; cin >> t >> l >> r;
        if(t == 2 || t == 4) r -= 0.5;
        if(t == 3 || t == 4) l += 0.5;
        if(l <= r) lr[i] = {l, r};
    }
    sort(lr.begin(), lr.end());
    int ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            if(lr[j].first <= lr[i].second){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}