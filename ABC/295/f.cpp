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

ll solve(string s, ll x){
    if(x <= 0) return 0;
    ll res = 0;

    string sx = to_string(x);
    int m = (int)sx.size();

    string t(m, '*');
    rep(i, 0, m){
        rep(k, 0, sx[i]-'0'){
            t[i] = (char)('0'+k);
            rep(j, 0, m){
                // s と t[j:] が一致するかどうか
                bool ok = true;
                rep(l, 0, (int)s.size()){
                    if(j+l < m && (t[j+l] == '*' || t[j+l] == s[l])) continue;
                    ok = false;
                    break;
                }
                if(!ok) continue;

                // t[j:j+s.size()] は決まったので，それ以外の決め方を考える
                ll cnt_l = 1, cnt_r = 1;
                bool is_zero = true;
                rep(l, 0, j){
                    if(t[l] == '*') cnt_l *= 10;
                    if(inr(1, t[l]-'0', 10)) is_zero = false;
                }
                if(s[0] == '0' && is_zero) cnt_l--;

                rep(l, j+s.size(), m){
                    if(t[l] == '*') cnt_r *= 10;
                }

                res += cnt_l*cnt_r;
            }
        }
        t[i] = sx[i];
    }

    rep(i, 0, m){
        if(m < i+s.size()) break;
        if(t.substr(i, s.size()) == s) res++;
    }

    return res;
}


int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll l, r; cin >> l >> r;
        cout << solve(s, r)-solve(s, l-1) << endl;

    }
    return 0;
}