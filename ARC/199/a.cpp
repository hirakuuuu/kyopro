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
    while(t--){
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        rep(i, 0, n){
            string s; cin >> s;
            rep(j, 0, n){
                a[i][j] = s[j]-'0';
            }
        }
        vector<int> r(n), c(n);
        rep(i, 0, n) cin >> r[i];
        rep(i, 0, n) cin >> c[i];

        vector<int> x(n), y(n);        
        // 1行目を全部 0 にする
        rep(i, 0, n){
            if(a[0][i] == 1){
                y[i] = 1-y[i];
                rep(j, 0, n){
                    a[j][i] = 1-a[j][i];
                }
            }
        }

        // 各行をフリップするかを決める
        rep(i, 1, n){
            // i 行目の総和を求める
            int sum = 0;
            rep(j, 0, n) sum += a[i][j];
            // (n+1)/2 以上だったらフリップ
            if(sum >= (n+1)/2){
                x[i] = 1-x[i];
                rep(j, 0, n) a[i][j] = 1-a[i][j];
            }
        }

        // 各列を合わせられるかを調べる
        bool ok = true;
        rep(i, 0, n){
            // i 列目の総和を求める
            int sum = 0;
            rep(j, 0, n){
                sum += a[j][i];
            }
            if(sum == c[i]) continue;
            else if(sum == n-c[i]){
                y[i] = 1-y[i];
                rep(j, 0, n){
                    a[j][i] = 1-a[j][i];
                }
            }else{
                ok = false;
                break;
            }
        }

        // 各行がそろっているかを調べる
        rep(i, 0, n){
            int sum = 0;
            rep(j, 0, n){
                sum += a[i][j];
            }
            if(sum != r[i]) ok = false;
        }

        if(ok){
            cout << "Yes" << endl;
            rep(i, 0, n) cout << x[i];
            cout << endl;
            rep(i, 0, n) cout << y[i];
            cout << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}