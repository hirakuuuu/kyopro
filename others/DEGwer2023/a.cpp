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
// https://atcoder.jp/contests/DEGwer2023/tasks/DEGwer2023_a

int main(){
    int n, k, t; cin >> n >> k >> t;
    vector<int> a(k);
    vector<int> cnt(n);
    ll ans = 0;
    rep(i, 0, k){
        cin >> a[i];
        a[i]--;
        if(cnt[a[i]] > 0) ans++;
        else cnt[a[i]]++;
    }

    pair<int, int> state = {0, -t};
    rep(i, 0, n){
        if(cnt[i]){
            pair<int, int> fix = {state.first+1, state.second};
            pair<int, int> unfix = {IINF, IINF};
            if(i-state.second >= t) unfix = {state.first, i};
            //cout << fix.first << ' ' << fix.second << ' ' << unfix.first << ' '<< unfix.second << endl;
            state = min(fix, unfix);
        }
        //cout << state.first << ' ' << state.second << endl;
    }

    cout << ans+state.first << endl;
    
    return 0;
}