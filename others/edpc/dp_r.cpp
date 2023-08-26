#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_r

int main(){
    ll n, k; cin >> n >> k;

    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }
    auto matmal = [&](vector<vector<ll>> &A, vector<vector<ll>> &B){
        vector<vector<ll>> C(n, vector<ll>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                rep(k, 0, n){
                    C[i][k] += A[i][j]*B[j][k];
                    C[i][k] %= MOD;
                }
            }
        }
        return C;
    };

    auto matpow = [&](vector<vector<ll>> &A, ll &N){
        vector<vector<ll>> C(n, vector<ll>(n));
        rep(i, 0, n){
            C[i][i] = 1;
        }

        ll tmp = N;
        while(tmp){
            if(tmp&1) C = matmal(C, A);
            A = matmal(A, A);
            tmp >>= 1;
        }

        return C;
    };

    vector<vector<ll>> cnt = matpow(a, k);
    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            ans += cnt[i][j];
            ans %= MOD;
        }
    }

    cout << ans << endl;
    
    return 0;
}