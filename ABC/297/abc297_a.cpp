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
// https://atcoder.jp/contests/abc297/tasks/abc297_a

int main(){
    int n, d; cin >> n >> d;
    vector<int> t(n);
    rep(i, 0, n) cin >> t[i];
    rep(i, 1, n){
        if(t[i]-t[i-1] <= d){
            cout << t[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}