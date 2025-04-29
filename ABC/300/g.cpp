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

/*
サンプル見るとわかるけど，最大ケースの答えが 2*10^9 くらい
 → 全探索はできないけど，効率的な探索をやれば解ける？

例えば半分全列挙
*/

int main(){
    ll n, p; cin >> n >> p;
    vector<int> prime;
    rep(i, 2, p+1){
        bool is_prime = true;
        for(int j = 2; j < i; j++){
            if(i%j == 0) is_prime = false;
        }
        if(is_prime){
            prime.push_back(i);
            // cout << i << endl;
        }
    }

    int m = (int)prime.size();
    vector<ll> q = {1};
    vector<ll> r = {1};
    rep(i, 0, m){
        if(q.size() > r.size()) swap(q, r);
        // q に prime[i] のべき乗をかけて追加
        vector<ll> q_ = q;
        for(auto qq: q_){
            ll tmp = qq;
            while(tmp*prime[i] <= n){
                tmp *= prime[i];
                q.push_back(tmp);
            }
        }
    }

    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    ll ans = 0;
    for(auto qq: q){
        ans += upper_bound(r.begin(), r.end(), n/qq)-r.begin();
    }
    cout << ans << endl;
    return 0;
}