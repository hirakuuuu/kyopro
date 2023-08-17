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
// https://atcoder.jp/contests/abc241/tasks/abc241_f

int main(){
    ll h, w, n; cin >> h >> w >> n;
    ll sx, sy; cin >> sx >> sy;
    ll gx, gy; cin >> gx >> gy;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<pair<ll, ll>> xy(n), yx(n);
    rep(i, 0, n){
        xy[i] = {x[i], y[i]};
        yx[i] = {y[i], x[i]};
    }
    sort(xy.begin(), xy.end());
    sort(yx.begin(), yx.end());

    map<ll, vector<ll>> obs_x, obs_y;
    rep(i, 0, n){
        obs_x[xy[i].first].push_back(xy[i].second);
        obs_y[yx[i].first].push_back(yx[i].second);
    }

    queue<pair<ll, ll>> que;
    que.push({sx, sy});
    map<pair<ll, ll>, bool> seen;
    map<pair<ll, ll>, ll> cnt;
    seen[{sx, sy}] = true;
    cnt[{sx, sy}] = 0;
    while(!que.empty()){
        auto [px, py] = que.front(); que.pop();

        // x方向
        auto itr = upper_bound(obs_y[py].begin(), obs_y[py].end(), px);
        if(itr != obs_y[py].end()){
            ll nx = *itr;
            nx--;
            if(!seen[{nx, py}]){
                que.push({nx, py});
                seen[{nx, py}] = true;
                cnt[{nx, py}] = cnt[{px, py}]+1;
            }
        }
        if(itr != obs_y[py].begin()){
            itr = prev(itr);
            ll nx = *itr;
            nx++;
            if(!seen[{nx, py}]){
                que.push({nx, py});
                seen[{nx, py}] = true;
                cnt[{nx, py}] = cnt[{px, py}]+1;
            }
        }

        // y方向
        itr = upper_bound(obs_x[px].begin(), obs_x[px].end(), py);
        if(itr != obs_x[px].end()){
            ll ny = *itr;
            ny--;
            if(!seen[{px, ny}]){
                que.push({px, ny});
                seen[{px, ny}] = true;
                cnt[{px, ny}] = cnt[{px, py}]+1;
            }
        }
        if(itr != obs_x[px].begin()){
            itr = prev(itr);
            ll ny = *itr;
            ny++;
            if(!seen[{px, ny}]){
                que.push({px, ny});
                seen[{px, ny}] = true;
                cnt[{px, ny}] = cnt[{px, py}]+1;
            }
        }
    }

    cout << (seen[{gx, gy}] ? cnt[{gx, gy}] : -1)  << endl;
     
    return 0;
}