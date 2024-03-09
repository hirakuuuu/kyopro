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
// https://atcoder.jp/contests/abc344/tasks/abc344_e

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int, int> l, r;
    rep(i, 0, n-1){
        l[a[i+1]] = a[i];
        r[a[i]] = a[i+1];
    }
    int q; cin >> q;
    int start = a[0];
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            l[y] = x;
            int xr = r[x];
            if(xr != 0){
                r[y] = xr;
                l[xr] = y;
            }
            r[x] = y;
        }else{
            int x; cin >> x;
            int xl = l[x], xr = r[x];
            if(xl != 0 && xr != 0){
                r[xl] = xr;
                l[xr] = xl;
            }else if(xl != 0){
                r[xl] = 0;
            }else if(xr != 0){
                l[xr] = 0;
                start = xr;
            }
            l[x] = r[x] = 0;
        }
    }
    int pos = start;
    while(r[pos] != 0){
        cout << pos << ' ';
        pos = r[pos];
    }
    cout << pos << endl;


    
    return 0;
}