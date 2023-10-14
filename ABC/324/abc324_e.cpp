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
// https://atcoder.jp/contests/abc324/tasks/abc324_e

int main(){
    ll n; cin >> n;
    string t; cin >> t;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<ll> cnt_l(n), cnt_r(n);
    rep(i, 0, n){
        int tmp = 0;
        rep(j, 0, s[i].size()){
            if(s[i][j] == t[tmp]) tmp++;
            if(tmp == t.size()) break;
        }
        cnt_l[i] = tmp;

        tmp = t.size()-1;
        rrep(j, s[i].size()-1, 0){
            if(s[i][j] == t[tmp]) tmp--;
            if(tmp == -1) break;
        }

        cnt_r[i] = t.size()-1-tmp;
    }

    sort(cnt_l.begin(), cnt_l.end());
    sort(cnt_r.begin(), cnt_r.end());

    ll ans = 0;
    rep(i, 0, n){
        ans += cnt_r.end()-lower_bound(cnt_r.begin(), cnt_r.end(), t.size()-cnt_l[i]);
    }
    cout << ans << endl;

    return 0;
}