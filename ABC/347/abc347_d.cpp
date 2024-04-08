#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int a, b;
    ll c; cin >> a >> b >> c;
    map<tuple<int, int, int>, pair<ll, ll>> memo;
    auto f = [&](auto self, int i, int a_, int b_) -> pair<ll, ll> {
        if(a_ < 0 || b_ < 0){
            return {-1, -1};
        }
        if(memo.find({i, a_, b_}) != memo.end()){
            return memo[{i, a_, b_}];
        }
        if(i == -1){
            if(a_ == 0 && b_ == 0){
                return memo[{i, a_, b_}] = {0LL, 0LL};
            }
            return memo[{i, a_, b_}] = {-1, -1};
        }
        if((c>>i)&1){
            pair<ll, ll> res = self(self, i-1, a_-1, b_);
            if(res.first != -1LL){
                return memo[{i, a_, b_}] = {res.first+(1LL<<i), res.second};
            }
            res = self(self, i-1, a_, b_-1);
            if(res.first != -1LL){
                return memo[{i, a_, b_}] = {res.first, res.second+(1LL<<i)};
            }
        }else{
            pair<ll, ll> res = self(self, i-1, a_-1, b_-1);
            if(res.first != -1LL){
                return memo[{i, a_, b_}] = {res.first+(1LL<<i), res.second+(1LL<<i)};
            }
            res = self(self, i-1, a_, b_);
            if(res.first != -1LL){
                
                return memo[{i, a_, b_}] = {res.first, res.second};
            }
        }
        return memo[{i, a_, b_}] = {-1, -1};
    };
    pair<ll, ll> ans = f(f, 59, a, b);
    if(ans.first != -1){
        cout << ans.first << ' ' << ans.second << endl;
        // cout << __popcount(ans.first) << ' ' << __popcount(ans.second) << ' ' << (ans.first^ans.second) << endl;
    }
    else cout << -1 << endl;
    return 0;
}