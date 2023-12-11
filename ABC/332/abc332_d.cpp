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
// https://atcoder.jp/contests/abc332/tasks/abc332_d

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> b[i][j];
        }
    }

    vector<int> ind_h(h), ind_w(w);
    iota(ind_h.begin(), ind_h.end(), 0);
    iota(ind_w.begin(), ind_w.end(), 0);
    int ans = IINF;
    do{
        do{
            bool f = true;
            rep(i, 0, h){
                rep(j, 0, w){
                    if(a[ind_h[i]][ind_w[j]] != b[i][j]){
                        f = false;
                    }
                }
            }
            if(f){
                int tmp = 0;
                vector<bool> seen(h);
                rep(i, 0, h){
                    rep(j, ind_h[i]+1, h){
                        if(seen[j]) tmp++;
                    }
                    seen[ind_h[i]] = true;
                }
                seen.assign(w, false);
                rep(i, 0, w){
                    rep(j, ind_w[i]+1, w){
                        if(seen[j]) tmp++;
                    }
                    seen[ind_w[i]] = true;
                }
                chmin(ans, tmp);
            }
        }while(next_permutation(ind_w.begin(), ind_w.end()));
    }while(next_permutation(ind_h.begin(), ind_h.end()));

    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}