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

int main() {
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string b, c; cin >> b >> c;

        {
            int zero_cnt_b = 0, zero_cnt_c = 0;
            rep(i, 0, n){
                if(b[i] == '0') zero_cnt_b++;
            }
            rep(i, 0, m){
                if(c[i] == '0') zero_cnt_c++;
            }
            if(zero_cnt_b%2 != zero_cnt_c%2 || zero_cnt_b < zero_cnt_c){
                cout << "no" << endl;
                continue;
            }
        }
        
        bool ok = true;

        rep(_, 0, 2){
            int p = 0;
            rep(i, 0, m){
                int now = b[p]-'0';
                while(p < n && now != c[i]-'0'){
                    p++;
                    if(p == n) break;
                    if(now == b[p]-'0') now = 1;
                    else now = 0;
                }
                if(p == n){
                    ok = false;
                    break;
                }
                p++;
                // cout << i << ' ' << p-1 << endl;
            }
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
        }
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;

    }
    return 0;
}