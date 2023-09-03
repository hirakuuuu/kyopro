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
// https://atcoder.jp/contests/abc318/tasks/abc318_f

// 明日解く

int main(){
    ll n; cin >> n;
    vector<ll> x(n), l(n);
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n) cin >> l[i];


    // 距離の順序が変わるような点はO(n^2)
    vector<ll> nx;
    rep(i, 0, n) nx.push_back(x[i]-1);
    rep(i, 0, n){
        rep(j, i+1, n){
            if((x[j]+x[i])%2 == -1) nx.push_back((x[j]+x[i])/2-1);
            else nx.push_back((x[j]+x[i])/2);
        }
    }
    sort(nx.begin(), nx.end());
    nx.erase(unique(nx.begin(), nx.end()), nx.end());

    ll ans = 0;
    // k <= nx[0] の場合
    ll k = nx[0], tmp = INF;
    rep(i, 0, n){
        ll dx = abs(x[i]-k);
        chmin(tmp, l[i]-dx);
    }
    if(tmp >= 0) ans += tmp+1;

    // nx[i] < k <= nx[i+1] の場合
    rep(i, 1, nx.size()){
        k = nx[i];
        int p = lower_bound(x.begin(), x.end(), k)-x.begin();
        vector<pair<ll, ll>> x_(n);
        rep(j, 0, n){
            if(j < p) x_[j] = {abs(x[j]-k), 0};
            else x_[j] = {abs(x[j]-k), 1};
        }
        sort(x_.begin(), x_.end());
        vector<ll> gra(2, INF);
        rep(j, 0, n){
            chmin(gra[x_[j].second], l[j]-x_[j].first);
        }
        ll min_x = max(nx[i-1]+1, nx[i]-gra[1]), max_x = min(nx[i], nx[i]+gra[0]);
        if(max_x-min_x+1 >= 0) ans += max_x-min_x+1;
    }

    // nx[nx.size()-1] < k の場合
    k = nx[nx.size()-1], tmp = INF;
    rep(i, 0, n){
        ll dx = k-x[i];
        chmin(tmp, l[n-i-1]-dx);
    }
    if(tmp >= 0) ans += tmp;

    cout << ans << endl;
    
    return 0;
}