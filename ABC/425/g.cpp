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
- 再帰的に考えると桁ごとに寄与を分けることができる
- 近いところしか min にならないと勘違いしていたので気を付ける

アライグマ「G問題は桁DPみたいなやつなのだ！　
例えばM=11なら、xの範囲を0～7と8～10みたいに最上位bitが0か1かで分けて、
そのbitの影響だけ先に計算しておいて再帰するのだ！」
*/

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    auto f = [&](auto self, vector<ll> &b, ll m, int k) -> ll {
        if(k == 0 || m == 0) return 0LL;

        ll mid = 1<<(k-1);
        vector<ll> b0, b1;
        for(auto bb: b){
            if(bb < mid) b0.emplace_back(bb);
            else b1.emplace_back(bb-mid);
        }

        if(m == mid<<1){
            if(b0.empty()) return self(self, b1, mid, k-1)*2+(1LL<<(2*k-2));
            if(b1.empty()) return self(self, b0, mid, k-1)*2+(1LL<<(2*k-2));
            return self(self, b0, mid, k-1)+self(self, b1, mid, k-1);
        }
        if(m <= mid){
            if(b0.empty()) return self(self, b1, m, k-1)+(m<<(k-1));
            return self(self, b0, m, k-1);
        }

        ll res = 0;
        if(b0.empty()) res += self(self, b1, mid, k-1)+(1LL<<(2*k-2));
        else res += self(self, b0, mid, k-1);
        if(b1.empty()) res += self(self, b0, m-mid, k-1)+((m-mid)<<(k-1));
        else res += self(self, b1, m-mid, k-1);
        return res;
    };
    cout << f(f, a, m, 30) << endl;

    return 0;
}