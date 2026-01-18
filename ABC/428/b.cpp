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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<string, int> cnt;
    int mx = 0;
    rep(i, 0, n-k+1){
        string t = s.substr(i, k);
        if(cnt.count(t)) continue;
        cnt[t] = 0;
        rep(j, 0, n-k+1){
            string ss = s.substr(j, k);
            if(ss == t) cnt[t]++;
        }
        chmax(mx, cnt[t]);
    }
    cout << mx << endl;
    for(auto [key, val]: cnt){
        if(val == mx){
            cout << key << ' ';
        }
    }
    cout << endl;
    return 0;
}