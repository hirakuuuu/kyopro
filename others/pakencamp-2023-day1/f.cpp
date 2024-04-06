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
// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/f

int main(){
    ll n; cin >> n;
    vector<ll> ans(n);
    ans[0] = 0, ans[n-1] = 1e9;
    rrep(i, n-2, 1){
        ans[i] = (ans[0]+ans[i+1])/2LL;
    }
    if(ans[0] == ans[1]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        rep(i, 0, n) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}