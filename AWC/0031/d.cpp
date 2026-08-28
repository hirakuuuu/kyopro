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

/*
おもしろい！！
- Rは降順にソートされてるとする
- このとき，答えがYESとなることと以下が必要十分
    - k = 1, 2, ... , M について， \sum_{i = 1}^{k} R[i] <= \sum_{i=1}^{n} min(L[i], k);

必要性は明らか，十分性も帰納法で示せる
*/

int main(){
    int n, m; cin >> n >> m;
    vector<ll> l(n);
    vector<ll> r(m);
    vector<ll> cnt_l(m+1);
    rep(i, 0, n) cin >> l[i], cnt_l[l[i]]++;
    rep(i, 0, m) cin >> r[i];
    sort(r.rbegin(), r.rend()); // 降順にソート（必要十分になるための条件）
    ll sum_r = 0;
    ll sum_l = 0;
    ll cnt = n;
    bool f = true;
    rep(i, 0, m){
        sum_r += r[i];
        sum_l += cnt;
        if(sum_r > sum_l) f = false;
        cnt -= cnt_l[i+1];
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}