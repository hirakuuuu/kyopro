#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc031/tasks/agc031_b

int main(){
    int n; cin >> n;
    vector<int> c(1);
    cin >> c[0];
    c[0]--;
    rep(i, 1, n){
        int C; cin >> C;
        C--;
        if(c.back() == C) continue;
        c.push_back(C);
    }

    int m = c.size();
    vector<int> l(200005, -1);
    l[c[0]] = 0;
    vector<ll> sum(m);
    ll ans = 0;
    rep(i, 1, m){
        if(l[c[i]] != -1){
            ans += sum[l[c[i]]]+1;
        }
        ans %= MOD;
        sum[i] = ans;
        l[c[i]] = i;
    }

    cout << (ans+1)%MOD << endl;

    return 0;
}