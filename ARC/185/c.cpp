#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

畳み込みで２つの異なる要素の和について、それぞれのペアの個数は求まる

====== upsolve ======

その後 k を固定したときに、i, j が存在するかを考えたい
a[i]+a[j] = x-a[k] かつ i \neq k かつ j\neq k を満たす i, j があればよい
これは 畳み込みで得た配列g と 各数字の個数の配列f から存在するかどうかは求まる
- g[x-a[k]]-(f[x-2*a[k]]-(a[k] == x-2*a[k])) が 1 以上かを判定
k があれば、i を固定して a[j] = x-a[i]-a[k] を満たす j を求める
- f[x-a[i]-a[k]] - (x-a[i]-a[k] == a[i]) - (x-a[i]-a[k] == a[k]) が１以上かを判定
- j は i, k と一致しないように選ぶ 

*/

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> cnt(x+1);
    vector<vector<int>> g(x+1);
    rep(i, 0, n){
        cnt[a[i]]++;
        g[a[i]].push_back(i);
    }

    vector<ll> cnt2 = convolution_ll(cnt, cnt);
    rep(i, 0, n) cnt2[2*a[i]]--;
    rep(i, 1, 2*x+1) cnt2[i] /= 2;
    
    vector<int> id(3, -1);
    rep(k, 0, n){
        ll rest = x-a[k];
        ll ng = 0;
        if(rest-a[k] >= 1){
            ng = cnt[rest-a[k]];
            if(rest-a[k] == a[k]) ng = cnt[rest-a[k]]-1;
        }
        if(cnt2[rest]-ng >= 1){
            id[2] = k;
            break;
        } 
    }
    if(id[2] == -1){
        cout << -1 << endl;
        return 0;
    }

    // id[0], id[1] を求める
    rep(i, 0, n){
        if(i == id[2]) continue;
        ll rest = x-a[i]-a[id[2]];
        if(rest <= 0) continue;
        ll ng = 0;
        if(rest == a[i]) ng++;
        if(rest == a[id[2]]) ng++;
        if(cnt[rest]-ng >= 1){
            id[0] = i;
            id[1] = g[rest][0];
            if(id[1] == id[0] || id[1] == id[2]) id[1] = g[rest][1];
            if(id[1] == id[0] || id[1] == id[2]) id[1] = g[rest][2];
            break;
        }
    }
    sort(id.begin(), id.end());
    rep(i, 0, 3) cout << id[i]+1 << ' ';
    cout << endl;

    return 0;
}