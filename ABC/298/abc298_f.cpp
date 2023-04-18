#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc298/tasks/abc298_f

int main(){
    ll n; cin >> n;
    vector<ll> r(n), c(n), x(n);
    map<ll, ll> sum_r, sum_c;
    map<pll, bool> exist;
    rep(i, 0, n){
        cin >> r[i] >> c[i] >> x[i];
        sum_r[r[i]] += x[i];
        sum_c[c[i]] += x[i];
        exist[{r[i], c[i]}] = true;
    }

    ll ans = 0;
    rep(i, 0, n){
        chmax(ans, sum_r[r[i]]+sum_c[c[i]]-x[i]);
    }

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    sort(r.begin(), r.end(), [&](ll a1, ll a2){ return sum_r[a1] > sum_r[a2]; });
    
    rep(i, 0, c.size()){
        rep(j, 0, r.size()){
            if(exist[{r[j], c[i]}]) continue;
            chmax(ans, sum_c[c[i]]+sum_r[r[j]]);
            break;
        }
    }
    cout << ans << endl;



    
    return 0;
}