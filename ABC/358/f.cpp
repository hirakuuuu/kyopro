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
    if(((m-1)+(n+m-2))%2 == k%2 || k < n){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<vector<char>> s(2*n+1, vector<char>(2*m+1, '?'));
    rep(i, 0, 2*m+1) s[0][i] = s[2*n][i] = '+';
    rep(i, 0, 2*n+1) s[i][0] = s[i][2*m] = '+';
    s[0][2*m-1] = 'S';
    s[2*n][2*m-1] = 'G';
    rep(i, 1, 2*n){
        if(i%2 == 1){
            rep(j, 1, 2*m) if(j%2 == 1) s[i][j] = 'o';
        }else{
            rep(j, 1, 2*m) if(j%2 == 0) s[i][j] = 'o';
        }
    }

    if(n%2 == 0){
        // nが偶数の時
        int tmp = k;
        rep(i, 0, n/2){
            int rest = tmp-2*(n/2-i-1);
            if(rest >= 2*m){
                // rep(j, 0, 2*m+1) if(s[4*i+1][j] == '?') s[4*i+1][j] = '.';
                rep(j, 2, 2*m+1) if(s[4*i+2][j] == '?') s[4*i+2][j] = '-';
                // rep(j, 0, 2*m+1) if(s[4*i+3][j] == '?') s[4*i+3][j] = '.';
                rep(j, 0, 2*m-1) if(s[4*i+4][j] == '?') s[4*i+4][j] = '-';
                tmp -= 2*m;
            }else if(rest > 0){
                rrep(j, m-1, m-1-rest/2+2){
                    s[4*i+2][2*j+1] = '-';
                }
                s[4*i+1][2*m-rest] = '|';
                s[4*i+3][2*m-rest] = '|';
                tmp -= rest;
            }
        }
    }else{
        // nが奇数の時
        int tmp = k;
        rep(i, 0, n/2-1){
            int rest = tmp-2*(n/2-i-1);
            if(rest >= 2*m){
                // rep(j, 0, 2*m+1) if(s[4*i+1][j] == '?') s[4*i+1][j] = '.';
                rep(j, 2, 2*m+1) if(s[4*i+2][j] == '?') s[4*i+2][j] = '-';
                // rep(j, 0, 2*m+1) if(s[4*i+3][j] == '?') s[4*i+3][j] = '.';
                rep(j, 0, 2*m-1) if(s[4*i+4][j] == '?') s[4*i+4][j] = '-';
                tmp -= 2*m;
            }else if(rest > 0){
                rrep(j, m-1, m-1-rest/2+2){
                    s[4*i+2][2*j+1] = '-';
                }
                s[4*i+1][2*m-rest] = '|';
                s[4*i+3][2*m-rest] = '|';
                tmp -= rest;
            }
        }
    }
    rep(i, 0, 2*n+1){
        rep(j, 0, 2*m+1){
            if(s[i][j] == '?') s[i][j] = '.';
            cout << s[i][j];
        }
        cout << endl;
    }


    return 0;
}