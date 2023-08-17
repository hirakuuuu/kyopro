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

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<int> y_ = y;
    sort(y_.begin(), y_.end());
    y_.erase(unique(y_.begin(), y_.end()), y_.end());

    map<int, int> y_index;
    rep(i, 0, y_.size()){
        y_index[y_[i]] = i;
    }

    vector<vector<pair<int, int>>> g(y_.size());
    rep(i, 0, n){
        g[y_index[y[i]]].emplace_back(make_pair(x[i], i));
    }

    string s; cin >> s;

    rep(i, 0, y_.size()){
        sort(g[i].begin(), g[i].end());
        bool f_l = false, f_r = false;
        rep(j, 0, g[i].size()){
            const auto [xx, id] = g[i][j];
            if(s[id] == 'R') f_r = true;
            else if(f_r) f_l = true;
        }

        if(f_l && f_r){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}