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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n, m, t, p; cin >> n >> m >> t >> p;
        if(n == 0 && m == 0 && t == 0 && p == 0) break;
        vector<vector<int>> cnt(n, vector<int>(m, 1));
        rep(_, 0, t){
            int d, c; cin >> d >> c;
            if(d == 1){
                if(n-c >= c){
                    vector<vector<int>> ncnt(n-c, vector<int>(m));
                    rep(i, 0, n-c){
                        rep(j, 0, m){
                            ncnt[i][j] += cnt[i][j];
                            if(n-2*c <= i){
                                ncnt[i][j] += cnt[n-c-i+(n-c-1)][j];
                            }
                        }
                    }
                    n -= c;
                    swap(cnt, ncnt);
                }else{
                    vector<vector<int>> ncnt(c, vector<int>(m));
                    rep(i, 0, c){
                        rep(j, 0, m){
                            ncnt[i][j] += cnt[n-1-i][j];
                            if(c-1-i < n-c){
                                ncnt[i][j] += cnt[i-2*c+n][j];
                            }
                        }
                    }
                    n = c;
                    swap(cnt, ncnt);
                }
            }else{
                if(m-c >= c){
                    vector<vector<int>> ncnt(n, vector<int>(m-c));
                    rep(i, 0, n){
                        rep(j, 0, m-c){
                            ncnt[i][j] += cnt[i][j+c];
                            if(j < c){
                                ncnt[i][j] += cnt[i][c-1-j];
                            }
                        }
                    }
                    m -= c;
                    swap(cnt, ncnt);
                }else{
                    vector<vector<int>> ncnt(n, vector<int>(c));
                    rep(i, 0, n){
                        rep(j, 0, c){
                            ncnt[i][j] += cnt[i][c-1-j];
                            if(j < m-c){
                                ncnt[i][j] += cnt[i][j+c];
                            }
                        }
                    }
                    m = c;
                    swap(cnt, ncnt);
                }
            }

            // rep(i, 0, n){
            //     rep(j, 0, m){
            //         cout << cnt[i][j] << ' ';
            //     }
            //     cout << endl;
            // }
        }

        // cout << n << ' ' << m << endl;
        rep(_, 0, p){
            int x, y; cin >> x >> y;
            x = n-1-x;
            // cout << x << ' ' << y << endl;
            cout << cnt[x][y] << endl;
        }
    }
    
    return 0;
}