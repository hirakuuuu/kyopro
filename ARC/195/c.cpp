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
    int t; cin >> t;
    int M = 100000000;

    auto R = [&](int x, int y) -> void {
        cout << "R " << x+M << ' ' << y+M << endl;
    };
    auto B = [&](int x, int y) -> void {
        cout << "B " << x+M << ' ' << y+M << endl;
    };
    while(t--){
        int r, b; cin >> r >> b;
        if(r&1){
            cout << "No" << endl;
            continue;
        }
        if(r == 0){
            if(b%2 == 0){
                cout << "Yes" << endl;
                B(0, 0);
                rep(i, 0, b/2) B(1+i, 1-i);
                rep(i, 0, b/2-1) B(b/2-1-i, i-(b/2-1));
            }else{
                cout << "No" << endl;
            }
        }else if(b&1){
            cout << "Yes" << endl;
            rep(i, 0, r/2) R(1, -i);
            rep(i, 0, r/2) R(0, i-r/2+1);
            B(0, 1);
            rep(i, 0, b/2) B(i+1, i+2);
            rep(i, 0, b/2) B(b/2+1-i, b/2-i);
        }else{
            cout << "Yes" << endl;
            rep(i, 0, r/2) R(0, -i);
            rep(i, 0, r/2) R(1, i-r/2+1);
            rep(i, 0, b/2) B(2+i, i);
            rep(i, 0, b/2) B(b/2-i, b/2-i);
        }
    }
    
    return 0;
}