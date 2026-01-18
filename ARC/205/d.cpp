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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n, -1);
        vector<vector<int>> g(n);
        rep(i, 1, n){
            cin >> p[i]; p[i]--;
            g[p[i]].push_back(i);
        }

        vector<int> c(n);
        auto f1 = [&](auto self, int pos) -> void {
            c[pos] = 1;
            for(auto nxt: g[pos]){
                self(self, nxt);
                c[pos] += c[nxt];
            }
        };
        f1(f1, 0);

        auto f2 = [&](auto self, int pos) -> int {
            if(g[pos].size() == 0){
                return 1;
            }
            if(g[pos].size() == 1){
                return self(self, g[pos][0])+1;
            }

            int sum = 0;
            int mx = 0;
            int mx_c = -1;
            for(auto nxt: g[pos]){
                sum += c[nxt];
                if(mx < c[nxt]){
                    mx = c[nxt];
                    mx_c = nxt;
                }
            }
            if(mx <= sum/2){
                return sum%2+1;
            }

            int len = self(self, mx_c);
            if(len <= sum-mx){
                return sum%2+1;
            }
            return len-(sum-mx)+1;
        };
        cout << (n-f2(f2, 0))/2 << endl;


    
    }
    
    return 0;
}