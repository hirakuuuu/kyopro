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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        // k <= 2^n なら YES
        if(n <= 20 && k > (1<<n)){
            cout << -1 << endl;
        }else{
            // nCj 個ずつ
            ll ans = 0;
            ll now = n;
            ll cnt = 0;
            ll tmp = 1;
            rrep(i, k-1, 1){
                cnt++;
                // cout << i << ' ' << tmp << endl;
                ans += tmp*to_string(i).size();
                if(now == cnt){
                    now *= n-tmp;
                    now /= tmp+1;
                    tmp++;
                    cnt = 0;
                }
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}