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
// https://atcoder.jp/contests/abc336/tasks/abc336_d

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> l(n), r(n);
    l[0] = 1;
    rep(i, 1, n){
        if(a[i] >= l[i-1]+1){
            l[i] = l[i-1]+1;
        }else{
            l[i] = a[i];
        }
    }
    r[n-1] = 1;
    rrep(i, n-2, 0){
        if(a[i] >= r[i+1]+1){
            r[i] = r[i+1]+1;
        }else{
            r[i] = a[i];
        }
    }

    int ans = 1;
    rep(i, 0, n){
        chmax(ans, min(l[i], r[i]));
    }
    cout << ans << endl;
    
    return 0;
}