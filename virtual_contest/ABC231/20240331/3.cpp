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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> tab(m), aab(m);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        tab[i] = {u, v};
    }
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        aab[i] = {u, v};
    }
    sort(aab.begin(), aab.end());
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do{ 
        vector<pair<int, int>> ntab(m);
        rep(i, 0, m){
            auto [u, v]  = tab[i];
            ntab[i] = {p[u], p[v]};
            if(ntab[i].first > ntab[i].second) swap(ntab[i].first, ntab[i].second);
        }
        sort(ntab.begin(), ntab.end());
        if(aab == ntab){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(p.begin(), p.end()));
    cout << "No" << endl;
    return 0;
}