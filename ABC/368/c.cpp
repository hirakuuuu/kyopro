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
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];

    ll t = 0;
    rep(i, 0, n){
        // h[i] が 0 以下になったときの T を求める
        while(h[i] > 0 && (t+1)%3){
            t++;
            h[i]--;
        }
        t += (h[i]/5)*3;
        h[i] %= 5;
        while(h[i] > 0){
            t++;
            if(t%3) h[i]--;
            else h[i] -= 3;
        }
    }
    cout << t << endl;
    
    return 0;
}