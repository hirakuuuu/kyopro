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

    auto f = [&](ll x, ll y) -> ll {
        if(x < 0 && y < 0) return -x-y;
        return abs(x-y);
    };

    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> p, m;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] > 0){
            p.push_back(a[i]);
        }else{
            m.push_back(a[i]);
        }
    }
    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    if(n == 2){
        cout << f(a[0], a[1]) << endl;
        return 0;
    }

    
    ll ans = 0;
    if(p.size() == 0){
        ans += -m[0]-m[1];
        rep(i, 2, m.size()) ans += -m[i]*2;
    }else if(p.size() == 1){
        m.push_back(-p[0]);
        sort(m.begin(), m.end());
        ans += -m[0]-m[1];
        rep(i, 2, m.size()) ans += -m[i]*2;
    }else if(m.size() == 0){
        rep(i, 0, n-1) ans += f(p[i], p[i+1]);
    }else if(m.size() == 1){
        ans += f(m[0], p[0]);
        rep(i, 0, n-2) ans += f(p[i], p[i+1]);
    }else{
        ans += -m[0]-m[1];
        rep(i, 2, (int)m.size()) ans += -m[i]*2;
        rep(i, 0, (int)p.size()-1){
            ans += f(p[i], p[i+1]);
        }
        ans += p[0]+p.back();
    }
    cout << ans << endl;

    
    return 0;
}