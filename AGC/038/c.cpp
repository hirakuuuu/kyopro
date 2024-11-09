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
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int m = 1000000;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<mint> cnt(m+1);
    rep(i, 0, n) cnt[a[i]]++;

    vector<mint> c2(m+1), inv(m+1);
    rep(i, 1, m+1){
        c2[i] = (cnt[i]*(cnt[i]-1))/2;
        inv[i] = mint(i).inv();
    }

    mint ans = 0;
    vector<mint> sum(m+1);
    rrep(g, m, 1){
        // 公約数に g を持つようなペア (i, j) の Σa[i]*a[j] を求める
        mint acc = 0;
        for(ll i = g; i <= m; i += g){
            // i 同士
            sum[g] += c2[i]*i*i; 
            // j < i で g が公約数のパターン
            sum[g] += acc*(cnt[i]*i);
            acc += cnt[i]*i;

            // 最大公約数が g でないパターンは除く
            if(i != g) sum[g] -= sum[i];
        }

        ans += sum[g]*inv[g];
    }
    cout << ans.val() << endl;
    
    return 0;
}