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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
string DRUL = "DRUL";

int main(){
    ll rt, ct, ra, ca; cin >> rt >> ct >> ra >> ca;
    ll n, m, l; cin >> n >> m >> l;

    vector<int> s(m), t(l);
    vector<ll> a(m), b(l);
    rep(i, 0, m){
        char c; cin >> c;
        rep(k, 0, 4){
            if(c == DRUL[k]) s[i] = k;
        }
        cin >> a[i];
    }
    rep(i, 0, l){
        char c; cin >> c;
        rep(k, 0, 4){
            if(c == DRUL[k]) t[i] = k;
        }
        cin >> b[i];
    }
    vector<tuple<ll, int, int>> event;
    ll acc_t = 0;
    rep(i, 0, m){
        event.emplace_back(acc_t, 0, s[i]);
        acc_t += a[i];
    }
    ll acc_a = 0;
    rep(i, 0, l){
        event.emplace_back(acc_a, 1, t[i]);
        acc_a += b[i];
    }
    event.emplace_back(n, 2, 5);
    sort(event.begin(), event.end());



    int e = event.size();
    int dt = -1, da = -1;
    auto check = [&](ll len) -> ll {
        if(rt == ra && ct == ca){
            return len*(dt == da);
        }
        if(dt == da){
            return 0;
        }
        if((dt == 1 || dt == 3) && (da == 1 || da == 3)){
            if(rt == ra && abs(ct-ca)%2 == 0){
                ll ky = -(ct-ca)/(dy[dt]-dy[da]);
                return (1 <= ky && ky <= len);
            }else{
                return 0;
            }
        }
        if((dt == 0 || dt == 2) && (da == 0 || da == 2)){
            if(ct == ca && abs(rt-ra)%2 == 0){
                ll kx = -(rt-ra)/(dx[dt]-dx[da]);
                return (1 <= kx && kx <= len);
            }else{
                return 0;
            }
        }
        ll kx = -(rt-ra)/(dx[dt]-dx[da]);
        ll ky = -(ct-ca)/(dy[dt]-dy[da]);
        return (kx == ky && 0 <= kx && kx <= len);
    };

    ll ans = 0;
    rep(i, 0, e-1){
        auto [Lt, at, dir] = event[i];
        auto [Rt, _, __] = event[i+1];
        
        if(at == 0){
            dt = dir;
        }else{
            da = dir;
        }
        if(dt == -1 || da == -1) continue;

        ll len = Rt-Lt;
        ans += check(len);
        rt += len*dx[dt];
        ct += len*dy[dt];
        ra += len*dx[da];
        ca += len*dy[da];
    }
    cout << ans << endl;



    
    return 0;
}