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
// https://atcoder.jp/contests/abc225/tasks/abc225_e

int main(){
    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<pair<pll, pll>> p(n);
    rep(i, 0, n){
        p[i].first = {x[i], y[i]-1};
        p[i].second = {x[i]-1, y[i]};
    }

    sort(p.begin(), p.end(), [](const auto &p1, const auto &p2){
        pll q1 = p1.second, q2 = p2.second;
        return q1.first*q2.second > q1.second*q2.first;
    });

    // for(auto pp: p){
    //     cout << pp.second.first << ' ' << pp.second.second << endl;
    // }

    int ans = 0;
    pll lim = {1, 0};
    rep(i, 0, n){
        pll q = p[i].first;
        if(q.first*lim.second <= q.second*lim.first){
            ans++;
            lim = p[i].second;
        }
    }

    cout << ans << endl;
    
    return 0;
}