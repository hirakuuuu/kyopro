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
    int step = 1;
    auto f = [&](auto self, pair<int, int> l, pair<int, int> r) -> void {
        if(r.first-l.first == 0){
            ans[l.first][l.second] = step++;
            return;
        }

        int N = r.first-l.first;
        rep(i, 0, N){
            if(i%2 == 0){
                ans[l.first][l.second+i] = step++;
                ans[r.first-i][r.second] = step++;
            }else{
                ans[r.first-i][r.second] = step++;
                ans[l.first][l.second+i] = step++;
            }
        }
        ans[l.first][r.second] = step++;
        ans[r.first][l.second] = step++;
        if((N-1)%2 == 0){
            rep(i, 1, N){
                if(i%2 == 1){
                    ans[r.first-i][l.second] = step++;
                    ans[r.first][l.second+i] = step++;
                }else{
                    ans[r.first][l.second+i] = step++;
                    ans[r.first-i][l.second] = step++;
                }
            }
        }else{
            rep(i, 1, N){
                if(i%2 == 0){
                    ans[r.first-i][l.second] = step++;
                    ans[r.first][l.second+i] = step++;
                }else{
                    ans[r.first][l.second+i] = step++;
                    ans[r.first-i][l.second] = step++;
                }
            }
        }

        if(N >= 2){
            l.first++, l.second++;
            r.first--, r.second--;
            self(self, l, r);
        }
    };

    f(f, {0, 0}, {n-1, n-1});

    rep(i, 0, n){
        rep(j, 0, n){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}