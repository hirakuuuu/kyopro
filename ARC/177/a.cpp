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
    vector<int> p = {1, 5, 10, 50, 100, 500};
    vector<int> cnt(6);
    rep(i, 0, 6) cin >> cnt[i];
    int n; cin >> n;
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n){
        int rest = x[i];
        rrep(j, 5, 0){
            if(cnt[j] == 0) continue;
            int tmp = min(cnt[j], rest/p[j]);
            cnt[j] -= tmp;
            rest -= tmp*p[j];
        }
        if(rest != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}