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

/**
 自明にダメなのをはじく
 条件を累積和で考えると簡単に構築できる
*/

int main(){
    int H, W, h, w; cin >> H >> W >> h >> w;
    if(H%h == 0 && W%w == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<vector<int>> a(H, vector<int>(W));
    ll sum = 0;
    if(H%h){
        vector<int> s(H+1);
        s[0] = 0;
        rep(i, 1, h) s[i] = 250000;
        rep(i, h, H+1) s[i] = s[i-h]-1;
        assert(s[H] > 0);
        rep(i, 0, H){
            rep(j, 0, W){
                a[i][j] = s[i+1]-s[i];
                sum += (ll)a[i][j];
            }
        }
        assert(sum > 0);
    }else{
        vector<int> s(W+1);
        s[0] = 0;
        rep(i, 1, w) s[i] = 250000;
        rep(i, w, W+1) s[i] = s[i-w]-1;
        assert(s[W] > 0);
        rep(i, 0, H){
            rep(j, 0, W){
                a[i][j] = s[j+1]-s[j];
                sum += (ll)a[i][j];
            }
        }
        assert(sum > 0);
    }
    rep(i, 0, H){
        rep(j, 0, W){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}