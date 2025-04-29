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

    // map<pair<ll, ll>, bool> memo;
    // memo[{0, 0}] = memo[{0, 1}] = memo[{1, 1}]= false;
    // auto f = [&](auto self, ll x, ll y) -> bool {
    //     if(x > y) swap(x, y);
    //     if(memo.count({x, y})) return memo[{x, y}];

    //     ll tmp = 2;
    //     bool res = false;
    //     while(tmp <= x){
    //         if(!self(self, x-tmp, y+tmp/2)) res = true;
    //         tmp += 2;
    //     }
    //     tmp = 2;
    //     while(tmp <= y){
    //         if(!self(self, x+tmp/2, y-tmp)) res = true;
    //         tmp += 2;
    //     }

    //     return memo[{x, y}] = res;
    // };

    // for(ll sum = 1; sum <= 100; sum++){
    //     for(ll x = 1; x <= sum-x; x++){
    //         if(!f(f, x, sum-x)){
    //             cout << x << ' ' << sum-x << endl;
    //         }
    //         // cout << x << ' ' << sum-x << ' ';
    //         // if(f(f, x, sum-x)) cout << "Alice" << endl;
    //         // else cout << "Brown" << endl;
    //     }
    // }

    ll x, y; cin >> x >> y;
    if(x > y) swap(x, y);
    if(y-x <= 1){
        cout << "Brown" << endl;
    }else{
        cout << "Alice" << endl;
    }
    
    return 0;
}