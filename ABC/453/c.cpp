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
    vector<ll> l(n);
    rep(i, 0, n){
        cin >> l[i];
    }

    int ans = 0;
    rep(i, 0, 1<<n){
        ll now = 0;
        int cnt = 0;
        rep(j, 0, n){
            ll nxt = now;
            if(i>>j&1){
                nxt += l[j];
            }else{
                nxt -= l[j];
            }
            if((now >= 0 && nxt < 0) || (now < 0 && nxt >= 0)) cnt++;
            now = nxt;
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}