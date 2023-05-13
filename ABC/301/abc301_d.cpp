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
// https://atcoder.jp/contests/abc301/tasks/abc301_d

int main(){
    string s; cin >> s;
    reverse(s.begin(), s.end());
    ll n; cin >> n;
    ll m = 0, l = s.size();
    rep(i, 0, l){
        if(s[i] == '1') m += (1LL<<i);
    }

    if(m > n){
        cout << -1 << endl;
        return 0;
    }

    reverse(s.begin(), s.end());
    rep(i, 0, l){
        if(s[i] == '?' and m+(1LL<<(l-i-1)) <= n){
            m += (1LL<<(l-i-1));
        }
    }
    cout << m << endl;
    
    return 0;
}