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
    int h, w; 
    ll X; cin >> h >> w >> X;
    int p, q; cin >> p >> q; p--, q--;
    vector<vector<ll>> s(h, vector<ll>(w));
    rep(i, 0, h) rep(j, 0, w) cin >> s[i][j];

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
    vector<vector<int>> seen(h, vector<int>(w));
    ll ans = s[p][q];
    seen[p][q] = 1;
    rep(k, 0, 4){
        int np = p+(k-1)%2, nq = q+(k-2)%2;
        if(!inr(0, np, h) || !inr(0, nq, w)) continue;
        que.push({s[np][nq], np, nq});
        seen[np][nq] = 1;
    }
    while(!que.empty()){
        auto [tmp, x, y] = que.top(); que.pop();
        if(tmp < (ans+X-1)/X){
            ans += tmp;
            rep(k, 0, 4){
                int nx = x+(k-1)%2, ny = y+(k-2)%2;
                if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
                if(seen[nx][ny]) continue;
                que.push({s[nx][ny], nx, ny});
                seen[nx][ny] = 1;
            }
        }else{
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}