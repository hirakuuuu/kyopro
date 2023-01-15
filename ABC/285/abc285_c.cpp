#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc285/tasks/abc285_c

int main(){
    string s; cin >> s;
    vector<ll> base(s.size()+1);
    base[0] = 1;
    rep(i, 1, s.size()+1){
        base[i] = base[i-1]*26;
    }
    ll ans = 1;
    rep(i, 1, s.size()){
        ans += base[i];
    }

    rep(i, 0, s.size()){
        ans += (s[i]-'A')*base[s.size()-i-1];
    }
    cout << ans << endl;

    
    return 0;
}