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
// https://atcoder.jp/contests/abc320/tasks/abc320_e

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> t(m), w(m), s(m);
    map<ll, pair<ll, ll>> S;
    map<ll, vector<ll>> W;
    vector<ll> time;
    rep(i, 0, m){
        cin >> t[i] >> w[i] >> s[i];
        S[t[i]] = {w[i], s[i]};
        time.push_back(t[i]);
        time.push_back(t[i]+s[i]);
    }
    sort(time.begin(), time.end());
    time.erase(unique(time.begin(), time.end()), time.end());

    vector<ll> ans(n);
    set<ll> r;
    rep(i, 0, n) r.insert(i);
    for(ll tt: time){
        for(auto ww: W[tt]){
            r.insert(ww);
        }
        if(r.size() && S[tt] != make_pair(0LL, 0LL)){
            ll tmp = *r.begin();
            ans[tmp] += S[tt].first;
            r.erase(r.begin());
            W[tt+S[tt].second].push_back(tmp);
        }
    }

    rep(i, 0, n){
        cout << ans[i] << '\n';
    }


    
    return 0;
}