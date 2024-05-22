#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
桁ごとに分けて考えられる
分けた後は 0, 1 の割り当てが全探索可能
*/

int main(){
    int n, q; cin >> n >> q;
    vector<tuple<int, int, int>> queri(q);
    vector<ll> w(q);
    rep(i, 0, q){
        int x, y, z; cin >> x >> y >> z;
        x--, y--, z--;
        queri[i] = {x, y, z};
        cin >> w[i];
    }

    mint ans = 1;
    rep(i, 0, 60){
        mint tmp = 0;
        rep(j, 0, 1<<n){
            bool ok = true;
            rep(l, 0, q){
                auto [x, y, z] = queri[l];
                if(w[l]>>i&1){
                    if((j>>x)&1 || (j>>y)&1 || (j>>z)&1) continue;
                }else{
                    if(!((j>>x)&1) && !((j>>y)&1) && !((j>>z)&1)) continue;             
                }
                ok = false;
            }
            if(ok) tmp += 1;
        }
        ans *= tmp;
    }
    cout << ans.val() << endl;

    return 0;
}