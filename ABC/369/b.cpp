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
    int n; cin >> n;
    int pl = -1, pr = -1;
    int ans = 0;
    rep(i, 0, n){
        int a; cin >> a;
        char s; cin >> s;
        if(s == 'L'){
            if(pl != -1) ans += abs(pl-a);
            pl = a;
        }else{
            if(pr != -1) ans += abs(pr-a);
            pr = a; 
        }
    }
    cout << ans << endl;
    
    return 0;
}