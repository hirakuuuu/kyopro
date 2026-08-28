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
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i]; b[i]--;
    }

    int m; cin >> m;
    vector<string> s(m);
    vector<vector<vector<ll>>> cnt(11, vector<vector<ll>>(10, vector<ll>(26)));
    rep(i, 0, m){
        cin >> s[i];
        rep(j, 0, s[i].size()){
            cnt[s[i].size()][j][s[i][j]-'a']++;
        }
    }

    rep(i, 0, m){
        if(s[i].size() != n){
            cout << "No" << endl;
            continue;
        }
        bool f = true;
        rep(j, 0, n){
            if(cnt[a[j]][b[j]][s[i][j]-'a']) continue;
            f = false;
        }
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}