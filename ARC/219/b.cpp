#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n);
        rep(i, 0, n){
            cin >> p[i]; p[i]--;
        }
        if(p[0] != 0){
            cout << 0 << endl;
            continue;
        }

        int ok = 1;
        rep(i, 1, n){
            if(p[i] == i) ok++;
            else break;
        }
        mint ans = 0;
        vector<int> s(n);
        iota(s.begin(), s.end(), 0);
        if(p == s) ans++;
        rep(j, 0, ok){
            ans += n-j-1;
        }
        cout << ans.val() << endl;
    }
    
    return 0;
}