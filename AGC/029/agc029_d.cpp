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
    int h, w, n; cin >> h >> w >> n;
    vector<vector<int>> obs(w);
    map<pair<int, int>, bool> exist;
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        x--, y--;
        obs[y].push_back(x);
        exist[{x, y}] = true;
    }
    rep(i, 0, w){
        sort(obs[i].begin(), obs[i].end());
        obs[i].push_back(h);
    }
    int r = obs[0][0]-1, l = 1;
    rep(i, 1, w){
        if(r <= l) break;
        if(r < i) break;
        int l_ = -1;
        if(i%2){
            // 奇数のときに移動できる
            rep(j, l, r+1){
                if(!exist[{j, i}]){
                    l_ = j;
                    break;  
                }
            }
        }else{
            // 偶数のときに移動できる
            rep(j, l, r+1){
                if(!exist[{j, i}]){
                    l_ = j;
                    break;
                }
            }
        }
        // cout << i << ' ' << l_ << ' ' << r << endl;
        if(l_ == -1){
            break;
        }
        int goal = (*upper_bound(obs[i].begin(), obs[i].end(), l_))-1;
        chmin(r, goal);
        l = l_+1;
        // cout << l << ' '  << r << ' ' << goal << endl;
    }

    cout << r+1 << endl;
    return 0;
}