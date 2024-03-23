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
// https://atcoder.jp/contests/agc012/tasks/agc012_b

int main(){
    ll n, w; cin >> n >> w;
    vector<pair<ll, ll>> cheeze(n);
    rep(i, 0, n){
        ll a, b; cin >> a >> b;
        cheeze[i] = {a, b};
    }
    sort(cheeze.rbegin(), cheeze.rend());
    ll ans = 0;
    int id = 0;
    while(id < n && w){
        if(w < cheeze[id].second){
            ans += cheeze[id].first*w;
            w = 0;
        }else{
            ans += cheeze[id].first*cheeze[id].second;
            w -= cheeze[id].second;
        }
        id++;
    }
    cout << ans << endl;

    
    return 0;
}