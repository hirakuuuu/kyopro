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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){

    int n, q; cin >> n >> q;
    vector<int> p(q), v(q);
    rep(i, 0, q) cin >> p[i] >> v[i];

    // 単調減少になっているところについて、その部分の操作方法が一意に定まる
    mint ans = 1;
    vector<bool> l(q), r(q);
    rep(i, 0, q){
        rep(j, i+1, q){
            // v[i] > v[j] となる j が存在するとき, i の操作方法は j から１通りに決まる
            // ２通り出てきたらだめ
            if(v[i] > v[j]){
                if(p[i] == p[j]){
                    ans = 0;
                }else if(p[i] < p[j]){
                    l[i] = r[j] = true;
                }else{
                    r[i] = l[j] = true;
                }
            }
        }
        if(l[i] && r[i]) ans = 0;
        else if(!l[i] && !r[i]) ans *= 2;
    }
    cout << ans.val() << endl;

    
    return 0;
}