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
// https://atcoder.jp/contests/abc203/tasks/abc203_e

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> x(m), y(m);
    rep(i, 0, m) cin >> x[i] >> y[i];

    vector<ll> x_ = x;
    sort(x_.begin(), x_.end());
    x_.erase(unique(x_.begin(), x_.end()), x_.end());
    map<ll, ll> xid;
    rep(i, 0, x_.size()){
        xid[x_[i]] = i;
    }
    vector<vector<ll>> pos(x_.size());
    rep(i, 0, m){
        pos[xid[x[i]]].push_back(y[i]);
    }

    set<ll> ans;
    ans.insert(n);
    rep(i, 0, pos.size()){
        vector<ll> del, add;
        rep(j, 0, pos[i].size()){
            if(ans.find(pos[i][j]-1) != ans.end() || ans.find(pos[i][j]+1) != ans.end()){
                add.push_back(pos[i][j]);
            }else{
                del.push_back(pos[i][j]);
            }
        }
        for(auto dd: del) ans.erase(dd);
        for(auto aa: add) ans.insert(aa);
    }

    cout << ans.size() << endl;
    
    return 0;
}