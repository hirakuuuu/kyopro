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
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> b(m);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--, y--;
        char C; cin >> C;
        int c = 0;
        if(C == 'B') c = 1;
        b[i] = {x, y, c};
    }

    sort(b.begin(), b.end());
    int mi_y = IINF;
    rep(i, 0, m){
        auto [x, y, c] = b[i];
        if(c){
            if(mi_y <= y){
                cout << "No" << endl;
                return 0;
            }
        }else{
            chmin(mi_y, y);
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}