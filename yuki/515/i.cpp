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
constexpr ll INF = 2e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int q; cin >> q;
    ll y; cin >> y;
    vector<string> s(q);
    rep(i, 0, q) cin >> s[i];

    auto f = [&](ll x) -> ll {
        stack<ll> stc;
        rep(i, 0, q){
            if(s[i] == "+"){
                ll a = stc.top(); stc.pop();
                ll b = stc.top(); stc.pop();
                stc.push(a+b);
            }else if(s[i] == "min"){
                ll a = stc.top(); stc.pop();
                ll b = stc.top(); stc.pop();
                stc.push(min(a, b));
            }else if(s[i] == "max"){
                ll a = stc.top(); stc.pop();
                ll b = stc.top(); stc.pop();
                stc.push(max(a, b));
            }else if(s[i] == "X"){
                stc.push(x);
            }else{
                stc.push(stol(s[i]));
            }
        }
        return stc.top();
    };
    
    ll zero = f(0LL);
    if(zero == y){
        cout << 0 << endl;
        return 0;
    }else if(zero > y){
        cout << -1 << endl;
        return 0;
    }

    ll ng = 0, ok = INF;
    if(f(2e9) >= y) ok = 2e9;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        if(f(mid) >= y) ok = mid;
        else ng = mid;
    }
    if(f(ok) != y){
        cout << -1 << endl;
    }else{
        cout << ok << endl;
    }
    return 0;
}