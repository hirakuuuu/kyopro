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
    string x, y; cin >> x >> y;
    vector<vector<ll>> acc_x(x.size()+1, vector<ll>(26));
    vector<vector<ll>> acc_y(y.size()+1, vector<ll>(26));
    rep(i, 0, x.size()){
        rep(j, 0, 26){
            acc_x[i+1][j] += acc_x[i][j];
            if(x[i]-'a' == j) acc_x[i+1][j]++;
        }
    }
    rep(i, 0, y.size()){
        rep(j, 0, 26){
            acc_y[i+1][j] += acc_y[i][j];
            if(y[i]-'a' == j) acc_y[i+1][j]++;
        }
    }


    vector<ll> s = {(ll)x.size(), (ll)y.size()};
    vector<vector<ll>> cnt(2, vector<ll>(26));
    rep(i, 0, s[0]) cnt[0][x[i]-'a']++;
    rep(i, 0, s[1]) cnt[1][y[i]-'a']++;
    while(s.size()%2 || s.back() < (ll)1e18){
        int sz = (int)s.size();
        s.push_back(s[sz-2]+s[sz-1]);
        cnt.push_back(vector<ll>(26));
        rep(i, 0, 26) cnt.back()[i] += cnt[sz-2][i]+cnt[sz-1][i];
    }
    // rep(i, 0, s.size()){
    //     cout << i+1 << ": " << s[i] << endl;
    //     rep(j, 0, 26){
    //         cout << cnt[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int m = s.size()-1;
    int q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        l--;
        char c; cin >> c;

        auto f = [&](auto self, int pos, ll pl, ll pr, int t) -> ll {
            // cout << pos << ' ' << pl << ' ' << pr << endl;
            if(pos == 0){
                return acc_x[pr][t]-acc_x[pl][t];
            }
            if(pos == 1){
                return acc_y[pr][t]-acc_y[pl][t];
            }
            if(pr-pl == s[pos]){
                return cnt[pos][t];
            }
            if(pr <= s[pos-1]){
                return self(self, pos-1, pl, pr, t);
            }else if(s[pos-1] <= pl){
                return self(self, pos-2, pl-s[pos-1], pr-s[pos-1], t);
            }
            return self(self, pos-1, pl, s[pos-1], t)+self(self, pos-2, 0, pr-s[pos-1], t);
        };

        cout << f(f, m, l, r, c-'a') << endl;
    }
    return 0;
}