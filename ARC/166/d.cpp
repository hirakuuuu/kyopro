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
constexpr ll INF = 1e10;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
区間の端の値として 左端は x+1, 右端は x-1 しか取らないと考えられる
そうすると, y の差分を考えたときに、それぞれ左端になる個数、右端になる個数を考えると条件を言い換えられる
- x[i]+1 が左端になる個数を a , x[i+1]-1 が右端になる個数を b とすると, y[i+1]-y[i] = a-b
- x[i] が含まれる区間の個数の差分を考えると分かる

ここまでできたら左端の集合と右端の集合が自明に分かるので, 昇順にして合わせてあげるだけ
この最適性の証明は、区間をずらしても答えが増加しないことから言える
*/

int main(){
    int n; cin >> n;
    vector<ll> x(n+2), y(n+2, 0);
    x[0] = -2*INF;
    rep(i, 1, n+1) cin >> x[i];
    rep(i, 1, n+1) cin >> y[i];
    x[n+1] = 2*INF;

    vector<ll> z(n+1);
    rep(i, 0, n+1) z[i] = y[i+1]-y[i];
    ll ans = INF;
    queue<pair<ll, ll>> que;
    rep(i, 0, n+1){
        if(z[i] > 0){
            que.push({x[i]+1, z[i]});
        }else if(z[i] < 0){
            ll rest = -z[i];
            while(rest){
                auto [l, cnt] = que.front(); // ここでpopして再度 push すると順番が変わるのでダメ
                chmin(ans, x[i+1]-1-l);
                if(rest >= cnt){
                    rest -= cnt;
                    que.pop();
                }else{
                    que.front().second -= rest;
                    rest = 0;
                }
            }
        }
    }
    if(ans >= (ll)1e10) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}