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
    vector<int> x(n), y(n), h(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> h[i];
    rep(cx, 0, 101){
        rep(cy, 0, 101){
            set<int> H;
            int mx = IINF;
            rep(i, 0, n){
                int dist = abs(x[i]-cx)+abs(y[i]-cy);
                if(h[i] == 0) chmin(mx, dist);
                else if(h[i]+dist > 0) H.insert(h[i]+dist);
            }
            if(H.size() == 1 && *H.begin() <= mx){
                cout << cx << ' ' << cy << ' ' << *H.begin() << endl;
                return 0;
            }
        }
    }
    return 0;
}