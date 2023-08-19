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
// https://atcoder.jp/contests/abc315/tasks/abc315_c

int main(){
    ll n; cin >> n;
    vector<ll> f(n), s(n);
    vector<vector<ll>> ice(n);
    rep(i, 0, n){
        cin >> f[i] >> s[i];
        f[i]--;
        ice[f[i]].push_back(s[i]);
    }

    rep(i, 0, n){
        sort(ice[i].begin(), ice[i].end());
        reverse(ice[i].begin(), ice[i].end());
    }

    ll ans = 0;
    rep(i, 0, n){
        if(ice[i].size() >= 2){
            chmax(ans, ice[i][0]+ice[i][1]/2);
        }
    }

    pair<ll, ll> q;
    rep(i, 0, n){
        if(ice[i].size() >= 1){
            if(q.first < ice[i][0]){
                q = {ice[i][0], q.second};
                if(q.first > q.second) swap(q.first, q.second);
            }
        }
    }

    if(q.first > 0) chmax(ans, q.first+q.second);
    cout << ans << endl;
    
    return 0;
}