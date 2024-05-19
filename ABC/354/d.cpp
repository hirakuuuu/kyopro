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

int main(){
    // ll a, b, c, d; cin >> a >> b >> c >> d;
    // ll ans = 0;
    // ll add = 0;
    // int mv = 0;
    // while((a%4+4+mv)%4 != (c%4+4)%4){
    //     int tmp = (a%4+4+mv)%4;
    //     if(tmp == 0){
    //         ans += 3*((d-b)/2);
    //         if((d-b)%2){
    //             if((b%2+2)%2 == 0) ans += 2;
    //             else ans += 1;
    //         }
    //     }else if(tmp == 1){
    //         ans += 3*((d-b)/2);
    //         if((d-b)%2){
    //             if((b%2+2)%2 == 1) ans += 2;
    //             else ans += 1;
    //         }
    //     }else if(tmp == 2){
    //         ans += ((d-b)/2);
    //         if((d-b)%2){
    //             if((b%2+2)%2 == 0) ans += 0;
    //             else ans += 1;
    //         }
    //     }else if(tmp == 3){
    //         ans += ((d-b)/2);
    //         if((d-b)%2){
    //             if((b%2+2)%2 == 0) ans += 1;
    //             else ans += 0;
    //         }
    //     }
    //     mv++;
    // }
    // ans += ((c-a)/4)*((d-b)/2)*8;
    // if((d-b)%2){
    //     ans += ((c-a)/4)*4;
    // }
    // cout << ans << endl;

    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll inf = -4e10;
    // 座標に合わせるときは上向きか下向きかをちゃんと考慮しないといけない
    vector<vector<int>> e = {
        {2, 1, 0, 1},
        {1, 2, 1, 0}
    };
    ll ans = 0;
    rep(i, 0, 2){
        rep(j, 0, 4){
            // 切り上げ
            ll dx = (c-j-inf+3)/4-(a-j-inf+3)/4;
            ll dy = (d-i-inf+1)/2-(b-i-inf+1)/2;
            ans += dx*dy*e[i][j];
        }
    }
    cout << ans << endl;


    return 0;
}