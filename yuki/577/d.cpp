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
    ll m; cin >> m;
    vector<pair<ll, ll>> p(n);
    rep(i, 0, n){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), [&](auto pi, auto pj){
        return (m-pi.first)/pi.second < (m-pj.first)/pj.second;
    });

    int ok = n, ng = 0;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        ll cnt = 1;
        bool f = true;
        for(int l = 0; l < n; l += mid){
            if(l+mid >= n) break;
            if(p[l+mid].first+p[l+mid].second*cnt > m) f = false;
            cnt++;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}