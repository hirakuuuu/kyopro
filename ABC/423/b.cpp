#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> l(n);
    rep(i, 0, n) cin >> l[i];

    vector<int> reach(n+1);
    reach[0] = reach[n] = 1;
    int pos = 0;
    while(pos < n && l[pos] == 0){
        pos++;
        reach[pos]++;
    }
    pos = n;
    while(pos >= 1 && l[pos-1] == 0){
        pos--;
        reach[pos]++;
    }

    int ans = 0;
    rep(i, 0, n+1) if(reach[i] == 0) ans++;
    cout << ans << endl;

    return 0;
}