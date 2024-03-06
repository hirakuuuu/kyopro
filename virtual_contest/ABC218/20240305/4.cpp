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
// 

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    vector<pair<int, int>> pos(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        pos[i] = {x[i], y[i]};
    }
    sort(pos.begin(), pos.end());
    int ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            if(x[i] == x[j] || y[i] == y[j]) continue;
            auto itr_1 = lower_bound(pos.begin(), pos.end(), make_pair(x[i], y[j]));
            auto itr_2 = lower_bound(pos.begin(), pos.end(), make_pair(x[j], y[i]));
            if(itr_1 != pos.end() && *itr_1 == make_pair(x[i], y[j]) && itr_2 != pos.end() && *itr_2 == make_pair(x[j], y[i])) ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}