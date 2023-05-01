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
// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_f

ll t[10], a[10], b[10];

int main(){
    rep(i, 0, 2) cin >> t[i];
    rep(i, 0, 2) cin >> a[i];
    rep(i, 0, 2) cin >> b[i];
    
    if(a[0] < b[0]) swap(a, b);

    // t0+t1分で進む距離が同じ場合のみ、無限に出会う
    if((t[0]*a[0]+t[1]*a[1]) == (t[0]*b[0]+t[1]*b[1])){
        cout << "infinity" << endl;
        return 0;
    }

    // Aが常に前にいるなら0
    if((t[0]*a[0]+t[1]*a[1]) > (t[0]*b[0]+t[1]*b[1])){
        cout << 0 << endl;
        return 0;
    }

    ll gap = (t[0]*b[0]+t[1]*b[1])-(t[0]*a[0]+t[1]*a[1]);
    ll ans = 1+((t[0]*(a[0]-b[0])+gap-1)/gap-1)*2+((t[0]*(a[0]-b[0]))%gap == 0);
    cout << ans << endl;






    
    return 0;
}