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
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    if(n == 1){
        if(a[0]%m == 0) cout << 2 << endl;
        else cout << 1 << endl;
        return 0;
    }

    vector<int> p;
    vector<vector<ll>> num_l(2);
    {
        auto f1 = [&](auto self, int pos) -> void {
            if(pos == n/2+1){
                ll tot = 0;
                bool f_r = false;
                for(auto pp: p){
                    tot += a[pp];
                    if(pp == n/2) f_r = true;
                }
                if(f_r) num_l[1].push_back(tot%m);
                else num_l[0].push_back(tot%m);
                return;
            }

            for(int i = pos+2; i <= n/2; i++){
                p.push_back(i);
                self(self, i);
                p.pop_back();
            }
            self(self, n/2+1);
            return;
        };
        rep(i, 0, n/2+1){
            p.push_back(i);
            f1(f1, i);
            p.pop_back();
        }
        num_l[0].push_back(0);
    }
    vector<vector<ll>> num_r(2);
    {
        auto f2 = [&](auto self, int pos) -> void {
            if(pos == n){
                ll tot = 0;
                bool f_r = false;
                for(auto pp: p){
                    tot += a[pp];
                    if(pp == n/2+1) f_r = true;
                }
                if(f_r) num_r[1].push_back(tot%m);
                else num_r[0].push_back(tot%m);
                return;
            }

            for(int i = pos+2; i < n; i++){
                p.push_back(i);
                self(self, i);
                p.pop_back();
            }
            self(self, n);
            return;
        };
        rep(i, n/2+1, n){
            p.push_back(i);
            f2(f2, i);
            p.pop_back();
        }
        num_r[0].push_back(0);
    }

    rep(i, 0, 2){
        sort(num_l[i].begin(), num_l[i].end());
        sort(num_r[i].begin(), num_r[i].end());
    }

    ll ans = 0;
    for(auto b: num_l[0]){
        ll c = (m-b)%m;
        ans += upper_bound(num_r[0].begin(), num_r[0].end(), c)-lower_bound(num_r[0].begin(), num_r[0].end(), c);
        ans += upper_bound(num_r[1].begin(), num_r[1].end(), c)-lower_bound(num_r[1].begin(), num_r[1].end(), c);
    }
    for(auto b: num_l[1]){
        ll c = (m-b)%m;
        ans += upper_bound(num_r[0].begin(), num_r[0].end(), c)-lower_bound(num_r[0].begin(), num_r[0].end(), c);
    }
    cout << ans << endl;
    return 0;
}