#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

/*
1 を含まないとすると，良い数列の長さは高々 10 じゃなかった
*/

int main(){
    ll n; cin >> n;
    vector<ll> y;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            y.push_back(i);
            if(n/i != i) y.push_back(n/i);
        }
    }
    sort(y.begin(), y.end());
    int m = y.size();
    unordered_map<ll, int> id;
    rep(i, 0, m) id[y[i]] = i;

    mint ans = 0;
    map<pair<ll, ll>, vector<pair<mint, mint>>> memo;
    auto f = [&](auto self, ll rest, ll mx) -> vector<pair<mint, mint>>{
        // cout << len << ' ' << tmp << ' ' << mx << ' ' << sum.val() << endl;
        if(memo.count({rest, mx})){
            return memo[{rest, mx}];
        }
        if(rest == 1){
            return {{1, 0}, {1, 1}};
        }
        vector<pair<mint, mint>> res(15);
        for(ll i = min(id[rest], id[mx]-1); i >= 1; i--){
            if(rest%y[i] == 0){
                vector<pair<mint, mint>> tmp = self(self, rest/y[i], y[i]);
                rep(j, 0, (int)tmp.size()){
                    res[j+1].first += tmp[j].first*(j+1);
                    res[j+1].second += tmp[j].second*(j+1)+tmp[j].first*(j+1)*y[i];
                }
            }
        }
        while(!res.empty() && res.back().first.val() == 0 && res.back().second.val() == 0) res.pop_back(); 
        return memo[{rest, mx}] = res;
    };
    vector<pair<mint, mint>> a = f(f, n, n);

    rep(i, 0, a.size()){
        ans += a[i].second;
    }
    if(n != 1) ans += n*3+2;
    cout << ans.val() << endl;

    return 0;
}