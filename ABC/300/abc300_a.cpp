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
// https://atcoder.jp/contests/abc300/tasks/abc300_a

int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n){
        if(c[i] == a+b){
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}