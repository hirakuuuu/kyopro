#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n), c(n);
    rep(i, 0, n) cin >> a[i] >> c[i];
    map<int, int> mi;
    rep(i, 0, n){
        if(mi.find(c[i]) == mi.end()){
            mi[c[i]] = a[i];
        }else{
            chmin(mi[c[i]], a[i]);
        }
    }
    int ans = 0;
    rep(i, 0, n) chmax(ans, mi[c[i]]);
    cout << ans << endl;

    
    
    return 0;
}