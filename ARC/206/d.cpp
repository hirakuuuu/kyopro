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
    vector<int> p = {4, 1, 3, 5, 2};
    while(t--){
        int n, k; cin >> n >> k;

        if(n == 1){
            if(k == 1) cout << 1 << endl;
            else cout << -1 << endl;
        }else if(n == 2){
            if(k == 2) cout << 1 << ' ' << 2 << endl;
            else cout << -1 << endl;
        }else if(n == 3){
            if(k == 3) cout << 1 << ' ' << 2 << ' ' << 3 << endl;
            else if(k == 2) cout << 1 << ' ' << 3 << ' ' << 2 << endl;
            else cout << -1 << endl;
        }else{
            if(k >= 2){
                rep(i, 1, n-k+1){
                    cout << i << ' ';
                }
                rrep(i, n, n-k+1){
                    cout << i << ' ';
                }
                cout << endl;
            }else if(k == 0){
                if(n <= 7){
                    cout << -1 << endl;
                }else{
                    rep(i, n/4+1, n/2+1) cout << i << ' ';
                    rrep(i, n, n*3/4+1) cout << i << ' ';
                    rrep(i, n/4, 1) cout << i << ' ';
                    rep(i, n/2+1, n*3/4+1) cout << i << ' ';
                    cout << endl;
                }
            }else{
                if(n <= 4){
                    cout << -1 << endl;
                }else{
                    rrep(i, n, 6) cout << i << ' ';
                    rep(i, 0, 5) cout << p[i] << ' ';
                    cout << endl;
                }
            }
        }

    }
    return 0;
}