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
// https://atcoder.jp/contests/arc169/tasks/arc169_c

int main(){
    int n; cin >> n;
    vector<int> a(3);
    rep(i, 0, 3) cin >> a[i];
    vector<int> l(n);
    rep(i, 0, n){
        cin >> l[i];
    }
    int total = 1;
    rep(i, 0, n) total *= 4;
    int ans = IINF;
    rep(i, 0, total){
        vector<int> d(n);
        int tmp = i;
        rep(j, 0, n){
            d[j] = tmp%4;
            tmp /= 4;
        }
        vector<int> m(3);
        int cur = 0;
        rep(j, 0, n){
            if(d[j] == 3) continue;
            if(m[d[j]] > 0) cur += 10;
            m[d[j]] += l[j];
        }
        bool ok = true;
        rep(j, 0, 3){
            if(m[j] == 0) ok = false;
            cur += abs(a[j]-m[j]);
        }
        if(ok) chmin(ans, cur);
    }
    cout << ans << endl;
    
    return 0;
}