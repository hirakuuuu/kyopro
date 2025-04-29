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
重ならないかつ，# がどこにあっても連結にできるを作る
両端の列をそれぞれでとって，交互に行を取るとそれが可能
*/

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h);
    rep(i, 0, h) cin >> a[i];

    vector<string> r(h, string(w, '.'));
    vector<string> b(h, string(w, '.'));
    rep(i, 0, h){
        r[i][0] = '#';
        b[i][w-1] = '#';
        if(i%2 == 0){
            rep(j, 0, w-1) r[i][j] = '#';
        }else{
            rep(j, 1, w) b[i][j] = '#';
        }
    }

    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] == '#') cout << '#';
            else cout << r[i][j];
        }
        cout << endl;
    }
    cout << endl;
    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] == '#') cout << '#';
            else cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}