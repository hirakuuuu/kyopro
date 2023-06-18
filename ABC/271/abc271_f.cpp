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
// https://atcoder.jp/contests/abc271/tasks/abc271_f

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    vector<map<int, int>> cnt(n);
    rep(i, 0, (1<<(n-1))){
        int tmp = a[0][0];
        int nx = 0, ny = 0;
        rep(j, 0, n-1){
            if((i>>j)&1) ny++;
            else nx++;

            tmp ^= a[nx][ny];
        }
        cnt[ny][tmp]++;
    }

    ll ans = 0;
    rep(i, 0, (1<<(n-2))){
        int tmp = a[n-1][n-1];
        int nx = n-1, ny = n-1;
        rep(j, 0, n-2){
            if((i>>j)&1) ny--;
            else nx--;

            tmp ^= a[nx][ny];
        }
        ans += cnt[ny][tmp]+cnt[ny-1][tmp];
    }

    cout << ans << endl;

    return 0;
}