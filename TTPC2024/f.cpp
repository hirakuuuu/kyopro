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
    int q; cin >> q;
    string TIOT = "TIOT";
    string ISCT = "ISCT";
    while(q--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        bool err = false;
        rep(i, 0, n-3){
            if(s[i] == t[i]) continue;
            if(s[i] == 'T' && t[i] == 'I'){
                if(s.substr(i, 4) == TIOT){
                    rep(j, 0, 4) s[i+j] = ISCT[j];
                }else{
                    err = true;
                }
            }else{
                err = true;
            }
        }
        // cout << s << ' ' << t << endl;
        rep(i, n-3, n){
            if(s[i] != t[i]) err = true;
        }

        if(err) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}