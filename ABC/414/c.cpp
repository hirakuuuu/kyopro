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
    int a; cin >> a;
    ll n; cin >> n;

    set<ll> ans;

    auto f = [&](ll num) -> string {
        string res;
        while(num){
            char c = (char)(num%a+'0');
            res = c+res;
            num /= a;
        }
        return res;
    };

    auto is_pal = [&](string s) -> bool {
        string t = s;
        reverse(t.begin(), t.end());
        return (s == t);
    };

    for(ll x = 1; x < 1000000; x++){
        {
            string s = to_string(x);
            string t = to_string(x);
            reverse(t.begin(), t.end());
            s += t;
            ll ns = stol(s);
            if(ns <= n && is_pal(f(ns))) ans.insert(ns);
        }
        {
            string s = to_string(x);
            string t = to_string(x);
            reverse(t.begin(), t.end());
            s.pop_back();
            s += t;
            ll ns = stol(s);
            if(ns <= n && is_pal(f(ns))) ans.insert(ns);
        }
    }
    // cout << f(11) << endl;
    // for(auto aa: ans){
    //     cout << aa << ' ' << f(aa) << endl;
    // }
    // cout << endl;

    ll tot = 0;
    for(auto aa: ans) tot += aa;
    cout << tot << endl;
    return 0;
}