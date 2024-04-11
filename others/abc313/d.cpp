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


int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n+1));
    rep(i, 0, n){
        cout << '?';
        rep(j, 0, k){
            cout << ' ' << (i+j)%n+1;
            a[i][(i+j)%n] = 1;
        }
        cout << endl;
        cin >> a[i][n];
    }

    rep(i, 0, n){
        rep(j, 0, n+1){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}