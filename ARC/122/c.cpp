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
    ll n; cin >> n;
    ll N = n;
    // フィボナッチ数列
    vector<ll> fib(2);
    fib[0] = fib[1] = 1;
    while(fib.back() <= n || fib.size()%2 == 0){
        fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
    }
    if(fib[fib.size()-2] > n) fib.pop_back(), fib.pop_back();

    vector<int> ans;
    int s = fib.size()-1;
    rep(i, 0, s+1){
        if(i > 0){
            ans.push_back(3+i%2);
        }
        if(n >= fib[s-i]){
            ans.push_back(1+i%2);
            n -= fib[s-i];
        }
    }
    // rep(i, 1, s+1){
    //     if(n >= fib[s-i]){
    //         ans.push_back(2-i%2);
    //         n -= fib[s-i];
    //     }
    //     ans.push_back(4-i%2);
    // }

    cout << ans.size() << endl;
    ll x = 0, y = 0;
    for(auto aa: ans){
        cout << aa << endl;
        if(aa == 1) x += 1;
        if(aa == 2) y += 1;
        if(aa == 3) x += y;
        if(aa == 4) y += x;
    }
    assert(x == N);
    return 0;
}