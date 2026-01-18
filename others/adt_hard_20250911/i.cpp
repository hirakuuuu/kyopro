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
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> cnt1(n);
    rep(i, 0, 1<<(n-1)){
        int pi = 0, pj = 0;
        int tmp = a[0][0];
        rep(j, 0, n-1){
            if((i>>j)&1){
                pi++;
            }else{
                pj++;
            }
            tmp ^= a[pi][pj];
        }
        cnt1[pi].push_back(tmp);
    }
    rep(i, 0, n){
        sort(cnt1[i].begin(), cnt1[i].end());   
    }

    vector<vector<int>> cnt2(n);
    rep(i, 0, 1<<(n-1)){
        int pi = n-1, pj = n-1;
        int tmp = a[n-1][n-1];
        rep(j, 0, n-1){
            if((i>>j)&1){
                pi--;
            }else{
                pj--;
            }
            tmp ^= a[pi][pj];
        }
        cnt2[pi].push_back(tmp);
    }
    rep(i, 0, n){
        sort(cnt2[i].begin(), cnt2[i].end());   
    }

    ll ans = 0;
    rep(i, 0, n){
        for(auto c1: cnt1[i]){
            int pl = lower_bound(cnt2[i].begin(), cnt2[i].end(), (c1^a[i][n-1-i]))-cnt2[i].begin();
            int pr = upper_bound(cnt2[i].begin(), cnt2[i].end(), (c1^a[i][n-1-i]))-cnt2[i].begin();
            ans += (ll)(pr-pl);
        }
    }
    cout << ans << endl;
    return 0;
}