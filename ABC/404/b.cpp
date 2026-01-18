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
    vector<string> s(n), t(n);
    rep(i, 0, n){
        cin >> s[i];
    }
    rep(i, 0, n){
        cin >> t[i];
    }

    int ans = IINF;
    rep(k, 0, 4){

        int cnt = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                if(s[i][j] != t[i][j]) cnt++;
            }
        }
        chmin(ans, cnt+k);

        vector<string> ns = s;
        rep(i, 0, n){
            rep(j, 0, n){
                ns[j][n-1-i] = s[i][j];
            }
        }
        swap(s, ns);

        // rep(i, 0, n){
        //     rep(j, 0, n){
        //         cout << s[i][j];
        //     }
        //     cout << endl;
        // }
    }
    cout << ans << endl;
    return 0;
}