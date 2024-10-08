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
{-1, 0, 1} → {0, 1, 2} に変えてみると、面倒なところが消えてくれることがある
今回の場合、全部 2 で初期化して、前から 0 でないものを選んで、-1 することで全てのパターンが作れる
このとき最適な操作は、p[i] が最小のモノを選ぶこと
*/

int main(){
    int n; cin >> n;
    vector<ll> p(n);
    rep(i, 0, n) cin >> p[i];

    priority_queue<ll> que;
    ll ans = 0;
    rep(i, 0, n){
        ans += p[i];
        que.push(-p[i]); que.push(-p[i]);
        ans += que.top(); que.pop();
    }
    cout << ans << endl;
    return 0;
}
