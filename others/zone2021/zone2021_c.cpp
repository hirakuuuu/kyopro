#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/zone2021/tasks/zone2021_c

int main(){
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(5));
    rep(i, 0, n){
        rep(j, 0, 5) cin >> a[i][j];
    }

    ll ok = 1, ng = 1000000001;
    auto check = [&](ll x) -> bool {
        set<int> s;
        rep(i, 0, n){
            int bit = 0;
            rep(j, 0, 5){
                bit <<= 1;
                bit |= (a[i][j] >= x);
            }
            s.insert(bit);
        }
        for(auto p: s) for(auto q: s) for(auto r: s){
            if((p|q|r) == 31) return 1;
        }
        return 0;
    };

    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}