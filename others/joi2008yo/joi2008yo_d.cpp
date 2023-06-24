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
// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d

int main(){
    int m; cin >> m;
    vector<pii> seiza(m);
    rep(i, 0, m) cin >> seiza[i].first >> seiza[i].second;


    int n; cin >> n;
    vector<pii> star(n);
    rep(i, 0, n) cin >> star[i].first >> star[i].second;

    map<pii, bool> star_exist;
    rep(i, 0, n) star_exist[star[i]] = true;

    rep(i, 0, n){
        pii offset = {star[i].first-seiza[0].first, star[i].second-seiza[0].second};
        bool ok = true;
        rep(j, 0, m){
            ok &= star_exist[{seiza[j].first+offset.first, seiza[j].second+offset.second}];
        }
        if(ok){
            cout << offset.first << ' ' << offset.second << endl;
            return 0;
        }

    }
    
    return 0;
}