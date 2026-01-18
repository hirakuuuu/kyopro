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
// using mint = modint998244353;
using mint = modint;

constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}


int main(){
    int n; cin >> n;
    ll m; cin >> m;
    // mint::set_mod(m);

    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n){
        cin >> a[i][j];
    }

    if(n == 1){
        cout << a[0][0]%m << endl;
        return 0;
    }

    ll q = power(10, n-1, m);
    vector<vector<ll>> upper(n);
    rep(i, 0, 1<<(n-1)){
        int pi = 0, pj = 0;
        ll tmp = a[0][0]%m;
        rep(j, 0, n-1){
            if((i>>j)&1) pi++;
            else pj++;
            tmp = (tmp*10+a[pi][pj])%m;
        }
        tmp = (tmp*q)%m;
        upper[pi].push_back(tmp);
    }
    rep(i, 0, n){
        sort(upper[i].begin(), upper[i].end());
        upper[i].erase(unique(upper[i].begin(), upper[i].end()), upper[i].end());
    }

    vector<vector<ll>> lower(n);
    rep(i, 0, 1<<(n-1)){
        int pi = n-1, pj = n-1;
        ll tmp = a[n-1][n-1]%m;
        ll ten = 10;
        rep(j, 0, n-1){
            if((i>>j)&1) pi--;
            else pj--;
            if(j != n-2) tmp = (ten*a[pi][pj]+tmp)%m;
            ten = (ten*10)%m;
        }
        lower[pi].push_back(tmp);
    }
    rep(i, 0, n){
        sort(lower[i].begin(), lower[i].end());
        lower[i].erase(unique(lower[i].begin(), lower[i].end()), lower[i].end());
    }

    ll ans = 0;
    rep(i, 0, n){
        for(auto uu: upper[i]){
            auto itr = lower_bound(lower[i].begin(), lower[i].end(), m-uu);
            if(itr != lower[i].begin()){
                chmax(ans, uu+*prev(itr));
            }else{
                chmax(ans, (uu+*lower[i].rbegin())%m);
            }
        }
    }
    cout << ans << endl;

    return 0;
}