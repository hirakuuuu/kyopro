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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int ans = 0;
    rep(i, 1, h-1){
        rep(j, 1, w-1){
            if(s[i][j] == '.') continue;
            bool ok = true;
            rep(k, 0, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(s[ni][nj] == '.') ok = false;
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}