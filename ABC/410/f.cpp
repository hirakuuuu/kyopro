# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

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
        int h, w; cin >> h >> w;
        vector<string> s(h);
        rep(i, 0, h){
            cin >> s[i];
        }
        if(h > w){
            vector<string> s_(w);
            rep(i, 0, w){
                rep(j, 0, h){
                    s_[i].push_back(s[j][i]);
                }
            }
            swap(s, s_);
            swap(h, w);
        }

        vector<vector<int>> acc(h+1, vector<int>(w+1));
        rep(i, 0, h){
            rep(j, 0, w){
                if(s[i][j] == '#') acc[i+1][j+1] = 1;
                else acc[i+1][j+1] = -1;
            }
        }
        rep(i, 1, h+1){
            rep(j, 1, w+1){
                acc[i][j] += acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
            }
        }

        ll ans = 0;
        vector<int> cnt(2*h*w+1);
        int off = h*w;
        rep(i, 0, h+1){
            rep(j, i+1, h+1){
                rep(l, 0, w+1){
                    ans += (ll)cnt[acc[j][l]-acc[i][l]+off];
                    cnt[acc[j][l]-acc[i][l]+off]++;
                }
                rep(l, 0, w+1){
                    cnt[acc[j][l]-acc[i][l]+off]--;
                }
            }
        }
      
        cout << ans << endl;
    }
    
    return 0;
}