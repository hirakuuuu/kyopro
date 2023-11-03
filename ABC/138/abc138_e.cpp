#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc138/tasks/abc138_e

int main(){
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string ss = s+s;
    vector<vector<int>> pos(26);
    rep(i, 0, 2*n){
        pos[ss[i]-'a'].push_back(i);
    }

    vector<vector<int>> nxt(n, vector<int>(26, -1));
    rep(i, 0, n){
        rep(j, 0, 26){
            auto itr = upper_bound(pos[j].begin(), pos[j].end(), i);
            if(itr == pos[j].end()) continue;
            nxt[i][j] = *itr-i;
        }
    }

    ll ans = n-1;
    rep(i, 0, m){
        ll tmp = ans%n;
        if(nxt[tmp][t[i]-'a'] == -1){
            cout << -1 << endl;
            return 0;
        }
        ans += nxt[tmp][t[i]-'a'];
    }
    ans -= n-1;
    cout << ans << endl;
    



    
    return 0;
}