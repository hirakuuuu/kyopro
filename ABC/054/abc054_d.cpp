#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc054/tasks/abc054_d

vector<int> a(40), b(40), c(40);
vector<vector<int>> min_cf(205, vector<int>(205, 1e9));
vector<vector<int>> min_cl(205, vector<int>(205, 1e9));

int main(){
    int n, ma, mb; cin >> n >> ma >> mb;
    rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];

    rep(i, 0, 1<<20){
        int A = 0, B = 0, C = 0;
        rep(j, 0, 20){
            if((i&(1<<j)) > 0){
                A += a[j];
                B += b[j];
                C += c[j];
            }
        }
        min_cf[A][B] = min(min_cf[A][B], C);
    }

    rep(i, 0, 1<<20){
        int A = 0, B = 0, C = 0;
        rep(j, 0, 20){
            if((i&(1<<j)) > 0){
                A += a[j+20];
                B += b[j+20];
                C += c[j+20];
            }
        }
        min_cl[A][B] = min(min_cl[A][B], C);
    }
    int ans = 1e9;
    rep(i, 0, 201){
        rep(j, 0, 201){
            rep(k, 1, 401){
                if(0 <= ma*k-i and ma*k-i < 201 and 0 <= mb*k-j and mb*k-j < 201){
                    ans = min(ans, min_cf[i][j]+min_cl[ma*k-i][mb*k-j]);
                }
            }
        }
    }

    if(ans != 1e9) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}