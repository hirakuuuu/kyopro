#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    vector<pair<ll, ll>> queri(n);
    rep(i, 0, n) queri[i] = {h[i], i+1};
    sort(queri.rbegin(), queri.rend());
    set<ll> done;
    done.insert(0);
    vector<ll> t(n+1);
    rep(i, 0, n){
        auto [H, r] = queri[i];
        auto itr = done.lower_bound(-r);
        int l = *itr;
        l *= -1;
        t[r] = t[l]+(r-l)*H;
        done.insert(-r);
    }

    rep(i, 1, n+1){
        cout << t[i]+1 << ' ';
    }
    cout << endl;

    
    return 0;
}