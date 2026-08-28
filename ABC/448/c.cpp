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
    multiset<ll> ms;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i]; ms.insert(a[i]);
    }

    while(q--){
        int k; cin >> k;
        vector<ll> b(k);
        rep(j, 0, k){
            cin >> b[j]; b[j]--;
            ms.erase(ms.find(a[b[j]]));
        }
        cout << *ms.begin() << '\n';
        rep(j, 0, k){
            ms.insert(a[b[j]]);
        }
    }
    
    
    return 0;
}