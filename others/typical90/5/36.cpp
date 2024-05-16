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

/*
マンハッタン距離は 45度回転でチェビシェフ距離になる
2次元以上でも同様に考えられる
https://atcoder.jp/contests/typical90/editorial/6397
*/

int main(){
    ll n, q; cin >> n >> q;
    vector<pair<ll, ll>> xy(n);
    vector<pair<ll, ll>> nxy(n);
    ll mx_x = -IINF, mx_y = -IINF;
    ll mi_x = IINF, mi_y = IINF;
    rep(i, 0, n){
        cin >> xy[i].first >> xy[i].second;
        nxy[i] = {xy[i].first-xy[i].second, xy[i].first+xy[i].second};
        chmax(mx_x, nxy[i].first);
        chmin(mi_x, nxy[i].first);
        chmax(mx_y, nxy[i].second);
        chmin(mi_y, nxy[i].second);
    }

    while(q--){
        ll Q; cin >> Q;
        Q--;
        cout << max(max(abs(mx_x-nxy[Q].first), abs(nxy[Q].first-mi_x)), max(abs(mx_y-nxy[Q].second), abs(nxy[Q].second-mi_y))) << endl;
    }

    return 0;
}