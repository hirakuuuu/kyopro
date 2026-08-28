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
    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<int>> mx(n, vector<int>(n));
    vector<vector<int>> mi(n, vector<int>(n));
    int used = 0;
    rep(i, 1, n){
        int tot = 0;
        rrep(j, n-2, 0){
            ans[i][j] = used+1-mi[i-1][j]-tot;
            tot += ans[i][j];
            used = mx[i-1][j]+tot;
        }
        mi[i][0] = mi[i-1][0]+ans[i][0];
        rep(j, 1, n-1){
            mi[i][j] = min(mi[i-1][j], mi[i][j-1])+ans[i][j];
        }

        mx[i][0] = mx[i-1][0]+ans[i][0];
        rep(j, 1, n-1){
            mx[i][j] = max(mx[i-1][j], mx[i][j-1])+ans[i][j];
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    vector<vector<int>> c(30, vector<int>(30));
    c[0][0] = 1;
    rep(i, 1, 30){
        c[i][0] = 1;
        rep(j, 1, i+1){
            c[i][j] = c[i-1][j]+c[i-1][j-1];
        }
    }
    {
        set<int> s;
        auto f = [&](auto self, int x, int y, int sum) -> void {
            if(x == n-1 && y == n-1){
                s.insert(sum+ans[x][y]);
                return;
            }
            if(x+1 < n){
                self(self, x+1, y, sum+ans[x][y]);
            }
            if(y+1 < n){
                self(self, x, y+1, sum+ans[x][y]);
            }
            return;
        };
        f(f, 0, 0, 0);
        assert(s.size() == c[2*n-2][n-1]);
    }
    return 0;
}