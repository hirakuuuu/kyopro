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
    ll sx, sy; cin >> sx >> sy;
    vector<ll> x(n), y(n);
    map<ll, set<ll>> hx, hy;
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        hx[x[i]].insert(y[i]);
        hy[y[i]].insert(x[i]);
    }

    vector<int> dy = {1, -1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};
    string UDLR = "UDLR";
    set<pair<ll, ll>> home;
    rep(i, 0, m){
        char d; cin >> d;
        ll c; cin >> c;
        rep(k, 0, 4){
            if(UDLR[k] == d){
                if(dx[k] != 0){
                    // x 方向の移動
                    if(dx[k] == 1){
                        auto itr = hy[sy].lower_bound(sx);
                        while(itr != hy[sy].end() && *itr <= sx+c){
                            home.insert({*itr, sy});
                            hy[sy].erase(itr++);
                        }
                        sx += c;
                    }else{
                        auto itr = hy[sy].lower_bound(sx-c);
                        while(itr != hy[sy].end() && *itr <= sx){
                            home.insert({*itr, sy});
                            hy[sy].erase(itr++);
                        }
                        sx -= c;
                    }
                }else{
                    // y 方向の移動
                    if(dy[k] == 1){
                        auto itr = hx[sx].lower_bound(sy);
                        while(itr != hx[sx].end() && *itr <= sy+c){
                            home.insert({sx, *itr});
                            hx[sx].erase(itr++);
                        }
                        sy += c;
                    }else{
                        auto itr = hx[sx].lower_bound(sy-c);
                        while(itr != hx[sx].end() && *itr <= sy){
                            home.insert({sx, *itr});
                            hx[sx].erase(itr++);
                        }
                        sy -= c;
                    }
                }
            }
        }
    }
    cout << sx << ' ' << sy << ' ' << home.size() << endl;
    
    return 0;
}