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
    string s; cin >> s;
    int n = (int)s.size();
    int k; cin >> k;

    // a[l][r] := [l, r) を削減して作れる文字列の長さの最小値
    vector<vector<int>> a(n+1, vector<int>(n+1));
    rep(i, 0, n+1){
        rep(j, i, n+1){
            a[i][j] = j-i;
        }
    }
    rep(range, 2, n+1){
        rep(l, 0, n+1-range){
            int r = l+range;
            rep(m, l+1, r){
                chmin(a[l][r], a[l][m]+a[m][r]);
            }
            if(s[l] == 'o'){
                if(s[l+1] == 'o'){
                    rep(m, l+1, r){
                        if(a[l+1][m] == 0){
                            if(s[m] == 'f'){
                                chmin(a[l][r], max(0, a[m+1][r]-k));
                            }else{
                                chmin(a[l][r], 1+a[m][r]);
                            }
                        }
                    }
                }else if(s[l+1] == 'f'){
                    chmin(a[l][r], max(0, a[l+2][r]-k));
                }
            }
        }
    }

    cout << a[0][n] << endl;
    
    return 0;
}