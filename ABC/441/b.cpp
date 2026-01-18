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
    int n, m; cin >> n >> m;
    vector<int> t(26), a(26);
    string tt; cin >> tt;
    rep(i, 0, n){
        t[tt[i]-'a']++;
    }
    string aa; cin >> aa;
    rep(i, 0, m){
        a[aa[i]-'a']++;
    }

    int q; cin >> q;
    while(q--){
        string w; cin >> w;
        bool ok_t = true, ok_a = true;
        rep(i, 0, (int)w.size()){
            if(!t[w[i]-'a']) ok_t = false;
            if(!a[w[i]-'a']) ok_a = false;
        }
        if(ok_t && !ok_a) cout << "Takahashi" << endl;
        else if(!ok_t && ok_a) cout << "Aoki" << endl;
        else cout << "Unknown" << endl;
    }

    return 0;
}