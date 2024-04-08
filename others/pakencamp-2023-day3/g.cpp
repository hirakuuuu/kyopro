#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        vector<int> p(k), q(k), r(n);
        rep(i, 0, n) cin >> r[i];
        vector<vector<int>> a(n);
        rep(i, 0, k){
            cin >> p[i] >> q[i];
            p[i]--, q[i]--;
            a[p[i]].push_back(i);
            a[q[i]].push_back(i);
        }
        bool ok = true;
        rep(i, 0, n){
            if(a[i].empty() && r[i] > 0){
                ok = false;
            }
        }
        int sum_r = 0;
        rep(i, 0, n){
            sum_r += r[i];
            sum_r %= m;
        }
        if(m%2 == 0 && sum_r%2 != 0){
            ok = false;
        }

        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}