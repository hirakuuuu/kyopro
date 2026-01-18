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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int off = 0;
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            int p, x; cin >> p >> x;
            p--;
            a[(p+off)%n] = x;
        }else if(t == 2){
            int p; cin >> p;
            p--;
            cout << a[(p+off)%n] << endl;
        }else{
            int k; cin >> k;
            off += k;
            off %= n;
            if(off < 0) off += n;
        }

        // rep(j, 0, n){
        //     cout << a[(j+off)%n] << ' ';
        // }
        // cout << endl;

    }
    
    return 0;
}