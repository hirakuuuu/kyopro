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
    while(true){
        int n = rand()%100+1;
        vector<int> x(n+1), y(n+1);
        vector<int> nx(n+1), ny(n+1);
        vector<vector<int>> a(n+1);
        vector<ll> hash(n+1);
        int base = 938298382;
        int mod = 998244353;
        rep(i, 1, n+1){
            nx[i] = x[i] = rand()%i;
            ny[i] = y[i] = rand()%100+1;
            a[i] = a[x[i]];
            a[i].push_back(y[i]);
            hash[i] = (hash[x[i]]*base+y[i])%mod;
        }

        map<ll, int> mx;
        rep(i, 0, n+1) mx[hash[i]] = i;
        vector<vector<pair<int, int>>> g(n+1);
        rep(i, 1, n+1){
            g[mx[hash[x[i]]]].push_back({y[i], i});
        }
        rep(i, 0, n+1){
            sort(g[i].begin(), g[i].end());
        }

        vector<int> p;
        auto f = [&](auto self, int pos, int pre) -> void {
            p.push_back(pos);
            for(auto [_, nxt]: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos);
            }
        };
        f(f, 0, -1);

        vector<int> ind(n+1);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](auto i, auto j){
            if(a[i] == a[j]) return i < j;
            return a[i] < a[j];
        });


        bool flag = true;
        rep(i, 1, n+1){
            if(ind[i] != p[i]){
                flag = false;
            }
        }
        if(flag) continue;
        cout << n << endl;
        rep(i, 1, n+1){
            cout << nx[i] << ' ' << ny[i] << endl;
        }
        rep(i, 1, n+1){
            cout << ind[i] << ' ';
        }
        cout << endl;
        rep(i, 1, n+1){
            cout << i << ": ";
            for(auto aa: a[i]){
                cout << aa << ' ';
            }
            cout << endl;
        }
        
        break;
    }
    return 0;
}