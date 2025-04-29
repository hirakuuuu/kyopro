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
先頭は a[1] でないとだめなのは明らか
そのすぐ後ろは使ってない最小値にできる（帰納法）
|a| = 1 になると降順に並べるしかない
*/

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    rep(i, 0, k) cin >> a[i], a[i]--;

    vector<int> used(n);
    vector<int> p;
    int mi = 0;
    rep(i, 0, k-1){
        p.push_back(a[i]);
        used[a[i]] = 1;
        if(a[i] != mi){
            p.push_back(mi);
            used[mi] = 1;
        }
        while(mi < n && used[mi]) mi++;
    }
    rrep(i, n-1, 0){
        if(!used[i]) p.push_back(i);
    }

    rep(i, 0, n){
        cout << p[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}