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
    int n, k, q; cin >> n >> k >> q;
    vector<ll> a(n);
    multiset<ll> l, r;
    rep(i, 0, n-k) l.insert(0);
    rep(i, n-k, n) r.insert(0);
    ll fa = 0;
    while(q--){
        ll x, y; cin >> x >> y;
        x--;
        if(*r.begin() <= a[x]){
            fa -= a[x];
            r.erase(r.find(a[x]));
            fa += y;
            r.insert(y);
        }else{
            l.erase(l.find(a[x]));
            l.insert(y);
        }
        a[x] = y;
        if(k != n && *l.rbegin() > *r.begin()){
            auto m1 = *l.rbegin();
            auto m2 = *r.begin();
            l.erase(l.find(m1));
            r.erase(r.find(m2));
            fa += m1;
            fa -= m2;
            l.insert(m2);
            r.insert(m1);
        }
        cout << fa << endl;
    }
    return 0;
}