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
// https://atcoder.jp/contests/abc081/tasks/arc086_b

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    ll max_abs = -1, max_abs_i = -1;
    rep(i, 0, n){
        cin >> a[i];
        if(max_abs < abs(a[i])){
            max_abs = abs(a[i]);
            max_abs_i = i;
        }
    }

    vector<pair<int, int>> ans;
    rep(i, 0, n){
        if(i == max_abs_i) continue;
        a[i] += a[max_abs_i];
        ans.push_back({max_abs_i+1, i+1});
    }

    if(a[0] >= 0){
        rep(i, 1, n){
            a[i] += a[i-1];
            ans.push_back({i, i+1});
        }
    }else{
        rrep(i, n-2, 0){
            a[i] += a[i+1];
            ans.push_back({i+2, i+1});
        }
    }

    cout << ans.size() << endl;
    for(auto [x, y]: ans){
        cout << x << ' ' << y << endl;
    }

    return 0;
}