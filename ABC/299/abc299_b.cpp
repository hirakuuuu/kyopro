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
// https://atcoder.jp/contests/abc299/tasks/abc299_b

int main(){
    int n, t;cin >> n >> t;
    vector<int> c(n), r(n);
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) cin >> r[i];

    int s = c[0];
    int max_t = 0, max_s = 0;
    int max_ti = 0, max_si = 1;
    rep(i, 0, n){
        if(c[i] == t and max_t < r[i]){
            max_t = r[i];
            max_ti = i+1;
        }else if(c[i] == s and max_s < r[i]){
            max_s = r[i];
            max_si = i+1;
        }
    }

    if(max_t > 0) cout << max_ti << endl;
    else cout << max_si << endl;

    
    return 0;
}