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
    vector<ll> a(n), b(n-1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> acc_l(n+1), acc_r(n+1);
    rep(i, 0, n-1){
        acc_l[i+1] = acc_l[i]+abs(a[i]-b[i]);
    }
    rrep(i, n-1, 1){
        acc_r[i] = acc_r[i+1]+abs(a[i]-b[i-1]);
    }

    ll mi = INF;
    rep(i, 0, n){
        chmin(mi, acc_l[i]+acc_r[i+1]);
    }
    set<int> l;
    rep(i, 0, n){
        if(acc_l[i]+acc_r[i+1] == mi){
            l.insert(a[i]);
        }
    }
    cout << l.size() << endl;
    for(auto L: l){
        cout << L << ' ';
    }
    cout << endl;
    
    return 0;
}