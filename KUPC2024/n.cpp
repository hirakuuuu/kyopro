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

    int n; cin >> n;
    if(n == 2){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<vector<int>> ans(n, vector<int>(n));
    if(n%2 == 1){
        rep(i, 0, n) rep(j, 0, n){
            if(i == j){
                ans[i][j] = 0;
            }else if(i > j){
                if((i+j)%2 == 1) ans[i][j] = 1;
                else ans[i][j] = -1;
            }else{
                if((i+j)%2 == 1) ans[i][j] = -1;
                else ans[i][j] = 1;
            }
        }
    }else{
        cout << "No" << endl;
        return 0;
    }

    // rep(i, 0, n/2){
    //     a.push_back((i+1));
    //     a.push_back(-(i+1));
    // }


    // rep(i, 0, n){
    //     rep(j, 0, n){
    //         ans[i][j] = a[(i-j+n)%n];
    //     }
    // }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    // validation
    rep(i, 0, n){
        int r_sum = 0, c_sum = 0;
        rep(j, 0, n){
            if(i != j) assert(ans[i][j] != ans[j][i]);
            r_sum += ans[i][j];
            c_sum += ans[j][i];
        }
        assert(r_sum == 0 && c_sum == 0);
    }
    
    return 0;
}