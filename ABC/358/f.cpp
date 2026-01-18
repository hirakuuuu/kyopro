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
    int n, m, k; cin >> n >> m >> k;
    if(k < n || n%2 != k%2){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<vector<char>> s(2*n+1, vector<char>(2*m+1));
    {
        rep(j, 0, 2*m-1) s[0][j] = '+';
        s[0][2*m-1] = 'S', s[0][2*m] = '+';
    }
    {
        rep(j, 0, 2*m-1) s[2*n][j] = '+';
        s[2*n][2*m-1] = 'G', s[2*n][2*m] = '+';
    }
    {
        for(int i = 1; i < 2*n; i += 2){
            s[i][0] = '+';
            rep(j, 1, 2*m){
                if(j%2 == 1) s[i][j] = 'o';
                else s[i][j] = '?';
            }
            s[i][2*m] = '+';
        }
    }
    {
        for(int i = 2; i < 2*n; i += 2){
            s[i][0] = '+';
            rep(j, 1, 2*m){
                if(j%2 == 1) s[i][j] = '?';
                else s[i][j] = '+';
            }
            s[i][2*m] = '+';
        }
    }
    rep(i, 0, 2*n+1){
        rep(j, 0, 2*m+1){
            cout << s[i][j];
        }
        cout << endl;
    }

    if(n%2 == 0){
        

    }else{

    }



    return 0;
}