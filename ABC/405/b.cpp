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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> cnt(m+1);
    rep(i, 0, n) cnt[a[i]]++;

    rep(i, 1, m+1){
        if(cnt[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    rrep(i, n-1, 0){
        cnt[a[i]]--;
        if(cnt[a[i]] == 0){
            cout << n-i << endl;
            break;
        }
    }
    
    return 0;
}