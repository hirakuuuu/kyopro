#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc063/tasks/arc075_b

int main(){
    ll n, a, b; cin >> n >> a >> b;
    ll c = a-b;
    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];

    sort(h.begin(), h.end());

    ll l = 0, r = 1e9+1;
    while(r-l > 0){
      ll m = (r+l)/2;
      int pos = upper_bound(h.begin(), h.end(), m*b)-h.begin();
      ll cnt = 0;
      rep(i, pos, n){
        cnt += (h[i]-m*b+c-1)/c;
      }

      if(cnt <= m) r = m;
      else l = m+1;
    }

    cout << l << endl;
    
    return 0;
}