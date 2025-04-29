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



int main(){
    int q; cin >> q;
    while(q--){
        ll l; cin >> l;
        vector<ll> a(2), b(2), x(2), y(2);
        rep(i, 0, 2){
            cin >> a[i] >> b[i] >> x[i] >> y[i];
        }

        // 購入可能かどうかと，予算をちょうど使い切るか
        bool ok = true;
        rep(i, 0, 2){
            if(a[i]*x[i]+b[i]*y[i] == l) continue;
            ok = false;
            break;
        }
        if(!ok){
            cout << "No" << endl;
            continue;
        }

        // // 入れ替えて，各々条件を満たさないならOK
        // if(max(a[0]*x[1]+b[0]*y[1], a[1]*x[0]+b[1]*y[0]) <= l){
        //     cout << "Yes" << endl;
        //     continue;
        // }

        // 入れ替えても OK な場合を検証
        ok = true;
        rep(i, 0, 2){
            if(a[i]*x[1-i]+b[i]*y[1-i] <= l){
                // i = 0 の場合を書く
                // f(x[0], y[0]) <= f(x[1], y[1]) が成り立つ
                if(a[1-i]*x[i]+b[1-i]*y[i] < l){
                    // (z, y[1]) (x[1] < z) が店 0 の条件を満たすので，
                    // f(z, y[1]) <= f(x[0], y[0]) が成り立つ
                    // f(x[1], y[1]) < f(z, y[1]) も成り立つので矛盾
                    ok = false;
                    break;
                }
            }
        }

        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }   
    return 0;
}
