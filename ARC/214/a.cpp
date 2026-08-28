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
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    rep(k, 0, 2*n-1){
        int tmp = -1;
        rep(i, 0, n){
            int j = k-i;
            if(!inr(0, j, n)) continue; 
            // cout << i << ' ' << j << ' ' << tmp << endl;
            if(s[i][j] != '?'){
                if(tmp == -1) tmp = s[i][j]-'0';
                else if(tmp != s[i][j]-'0'){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        if(tmp == -1) tmp = 0;
        rep(i, 0, n){
            int j = k-i;
            if(!inr(0, j, n)) continue; 
            s[i][j] = (char)'0'+tmp;
        }
    }

    rep(i, 0, n) cout << s[i] << endl;
    
    return 0;
}