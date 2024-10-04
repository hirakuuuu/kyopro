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
- 2m-1 個の区間の左端、右端、得点を求めておくと実装が樂
- 各矢の間隔は D で固定できる. 
- 最も左の矢を固定すると, 各区間の寄与を計算することで O(M) で得点が計算できる
- 最も左の矢を全探索したい → 余りを固定して D 通りにできそう
- 中心に近い方がよいので、不等式を立てると, x = floor(ND/2), ... , floor(ND/2)+D-1 のD通りになる
- 得点の計算の部分も, 各区間の寄与の変化が高々 2 開始か起こらないので, いもす法で高速化できる
*/

int main(){
    ll n, m, d; cin >> n >> m >> d;
    vector<ll> x(m+1), s(m);
    rep(i, 0, m+1) cin >> x[i];
    rep(i, 0, m) cin >> s[i];

    vector<ll> L(2*m-1), R(2*m-1), S(2*m-1);
    rrep(i, m-1, 1){
        L[m-1-i] = -x[i+1];
        R[m-1-i] = -x[i];
        S[m-1-i] = s[i];
    }
    L[m-1] = -x[1], R[m-1] = x[1]+1, S[m-1] = s[0];
    rep(i, 2, m+1){
        L[m-2+i] = x[i-1]+1;
        R[m-2+i] = x[i]+1;
        S[m-2+i] = s[i-1];
    }

    vector<ll> imos(d+1);
    ll a = -(n*d/2);
    rep(i, 0, 2*m-1){
        // cout << L[i] << ' ' << R[i] << ' ' << S[i] << endl;
        // 最も左の矢を x としたとき, 座標 R 未満に入る矢の本数 : max(min(ceil((R-x)/D), N), 0) 
        if(L[i]-a >= n*d){
            imos[0] -= n*S[i];
            imos[d] += n*S[i];
        }else if(L[i]-a >= 1){
            imos[0] -= (L[i]-a+d)/d*S[i]; 
            imos[(L[i]-a)%d] += S[i];  // ここで矢が1つ増える
            imos[d] += (L[i]-a)/d*S[i];
        }
        if(R[i]-a >= n*d){
            imos[0] += n*S[i];
            imos[d] -= n*S[i];
        }else if(R[i]-a >= 1){
            imos[0] += (R[i]-a+d)/d*S[i]; 
            imos[(R[i]-a)%d] -= S[i];  // ここで矢が1つ減る
            imos[d] -= (R[i]-a)/d*S[i];
        }
    }
    rep(i, 0, d) imos[i+1] += imos[i];
    cout << *max_element(imos.begin(), imos.end()) << endl;
    return 0;
}