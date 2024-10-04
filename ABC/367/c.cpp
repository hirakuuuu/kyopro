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
    int n, k; cin >> n >> k;
    vector<int> r(n);
    rep(i, 0, n) cin >> r[i];

    vector<int> a(n);
    auto f = [&](auto self, int pos, int sum) -> void {
        if(pos == n){
            if(sum%k != 0) return;
            rep(i, 0, n) cout << a[i] << ' ';
            cout << endl;
            return;
        }
        rep(i, 1, r[pos]+1){
            a[pos] = i;
            self(self, pos+1, sum+i);
            a[pos] = 0;
        }
    };
    f(f, 0, 0);

    
    return 0;
}