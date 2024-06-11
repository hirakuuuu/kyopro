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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> t(10, 1);
    rep(i, 1, n+1) t[i] = t[i-1]*3;
    int h = t[n];
    
    vector<vector<char>> ans(h, vector<char>(h, '?'));

    auto f = [&](auto self, int si, int sj, int w) -> void {
        if(w == 1){
            ans[si][sj] = '#';
            return; 
        }
        rep(i, 0, 3){
            rep(j, 0, 3){
                int nsi = si+(w/3)*i, nsj = sj+(w/3)*j;
                if(i == 1 && j == 1){
                    rep(k, 0, w/3) rep(l, 0, w/3){
                        ans[nsi+k][nsj+l] = '.';
                    }
                }else{
                    self(self, nsi, nsj, w/3);
                }
            }
        }
    };
    f(f, 0, 0, h);
    rep(i, 0, h){
        rep(j, 0, h){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}