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
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<vector<int>> pre(n, vector<int>(26, -1));
    vector<int> pos(26, -1);
    rep(i, 0, n){
        rep(j, 0, 26){
            pre[i][j] = pos[j];
        }
        pos[s[i]-'a'] = i;
    }

    ll ans = 0;
    rep(r, 0, n){
        int l = r;
        bool f = true;
        rrep(j, m-1, 0){
            if(l < 0){
                f = false;
                break;
            }
            if(s[l] != t[j]){
                l = pre[l][t[j]-'a'];
            }
            l--;
        }
        // cout << r << ' ' << l << endl;
        if(f){
            ans += (ll)(r-l-1);
        }else{
            ans += r+1;
        }
    }
    cout << ans << endl;

    return 0;
}