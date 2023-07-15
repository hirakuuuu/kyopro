#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc310/tasks/abc310_b

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(n), c(n);
    vector<vector<bool>> f(n, vector<bool>(m));
    rep(i, 0, n){
        cin >> p[i] >> c[i];
        rep(j, 0, c[i]){
            int F; cin >> F;
            f[i][F-1] = true;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;

            bool flag1 = (p[i] >= p[j]);
            bool flag2 = true;
            bool flag3 = (p[i] > p[j]);
            rep(k, 0, m){
                if(f[i][k] && !f[j][k]){
                    flag2 = flag3 = false;
                }
                if(!f[i][k] && f[j][k]){
                    flag3 = true;
                }
            }

            if(flag1 && flag2 && flag3){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }    

    cout << "No" << endl;
    
    return 0;
}