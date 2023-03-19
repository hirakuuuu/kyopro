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
// https://atcoder.jp/contests/abc294/tasks/abc294_c

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(n+m);
    map<int, int> pos;
    rep(i, 0, n){
        cin >> a[i];
        c[i] = a[i];
    }
    rep(i, 0, m){
        cin >> b[i];
        c[n+i] = b[i];
    }

    sort(c.begin(), c.end());
    rep(i, 0, n+m) pos[c[i]] = i+1;

    rep(i, 0, n) cout << pos[a[i]] << ' ';
    cout << endl;
    rep(i, 0, m) cout << pos[b[i]] << ' ';
    cout << endl;

    
    return 0;
}