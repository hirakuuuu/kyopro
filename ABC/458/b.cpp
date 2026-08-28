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
    int h, w; cin >> h >> w;
    if(h == 1 && w == 1){
        cout << 0 << endl;
    }else if(h == 1){
        rep(j, 0, w){
            int d = 2;
            if(j == 0 || j == w-1) d--;
            cout << d << ' ';
        }
        cout << endl;
    }else if(w == 1){
        rep(i, 0, h){
            int d = 2;
            if(i == 0 || i == h-1) d--;
            cout << d << endl;
        }
    }else{
        rep(i, 0, h){
            rep(j, 0, w){
                int d = 4;
                if(i == 0 || i == h-1) d--;
                if(j == 0 || j == w-1) d--;
                cout << d << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}