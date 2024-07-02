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
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<vector<int>> mb(29, vector<int>(n));
    rep(i, 0, 29){
        rep(j, 0, n){
            mb[i][j] = b[j]%(1<<i+1);
        }
        sort(mb[i].begin(), mb[i].end());
    }
    vector<int> cnt(29);
    rep(i, 0, n){
        rep(j, 0, 29){
            int tmp = a[i]%(1<<j+1);
            auto cnt1 = lower_bound(mb[j].begin(), mb[j].end(), 2*(1<<j)-tmp)-lower_bound(mb[j].begin(), mb[j].end(), (1<<j)-tmp);
            auto cnt2 = lower_bound(mb[j].begin(), mb[j].end(), 4*(1<<j)-tmp)-lower_bound(mb[j].begin(), mb[j].end(), 3*(1<<j)-tmp);
            cnt[j] += (cnt1+cnt2);
        }
    }
    int ans = 0;
    rep(i, 0, 29){
        if(cnt[i]%2) ans += (1<<i);
    }
    cout << ans << endl;


    
    return 0;
}