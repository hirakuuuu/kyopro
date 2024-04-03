#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc345/tasks/abc345_d

int main(){
    int n, h, w; cin >> n >> h >> w;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<vector<int>> used(h, vector<int>(w));
    auto dfs = [&](auto self, int t, int curi, int curj) -> bool {
        while(used[curi][curj]){
            curj++;
            if(curj >= w){
                curi++; curj = 0;
            }
            if(curi >= h) break;
        }
        if(curi >= h){
            return true;
        }
        bool f = false;
        rep(i, 0, n){
            if((t>>i)&1){
                rep(_, 0, 2){
                    if(curi+a[i] <= h && curj+b[i] <= w){
                        bool ok = true;
                        rep(j, curi, curi+a[i]){
                            rep(k, curj, curj+b[i]){
                                if(used[j][k] == 1) ok = false;
                            }
                        }
                        if(ok){
                            rep(j, curi, curi+a[i]){
                                rep(k, curj, curj+b[i]){
                                    used[j][k] = 1;
                                }
                            }
                            f |= self(self, t-(1<<i), curi, curj);
                            rep(j, curi, curi+a[i]){
                                rep(k, curj, curj+b[i]){
                                    used[j][k] = 0;
                                }
                            }
                        }
                    }
                    swap(a[i], b[i]);
                }
            }
        }
        return f;
    };
    if(dfs(dfs, (1<<n)-1, 0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}