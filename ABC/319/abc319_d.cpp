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
// https://atcoder.jp/contests/abc319/tasks/abc319_d

int main(){
    int n, m; cin >> n >> m;
    vector<ll> l(n);
    ll max_l = 0, sum_l = 0;
    rep(i, 0, n){
        cin >> l[i];
        chmax(max_l, l[i]);
        sum_l += l[i];
    }

    ll ok = sum_l+n-1, ng = max_l-1;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        ll cnt = 1, len = -1;
        rep(i, 0, n){
            if(len+l[i]+1 <= mid){
                len += l[i]+1;
            }else{
                cnt++;
                len = l[i];
            }
        }

        if(cnt <= m) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}