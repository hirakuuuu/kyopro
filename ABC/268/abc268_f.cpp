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
// https://atcoder.jp/contests/abc268/tasks/abc268_f

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<vector<ll>> c(n);
    rep(i, 0, n){
        ll l = 0, r = 0;
        for(auto ss: s[i]){
            if(ss == 'X') l++;
            else r += ss-'0';
        }
        c[i] = {-l, r, i};
    }
    sort(c.begin(), c.end(), [&](vector<ll> a, vector<ll> b) {
        return (-b[0])*a[1] < (-a[0])*b[1];
    });
    string t;
    rep(i, 0, n) t += s[c[i][2]];
    
    ll ans = 0, tmp = 0;
    for(auto tt: t){
        if(tt == 'X') tmp++;
        else ans += (tt-'0')*tmp;
    }
    cout << ans << endl;
    
    return 0;
}