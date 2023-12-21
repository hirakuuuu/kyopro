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
// https://atcoder.jp/contests/abc237/tasks/abc237_b

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(w, vector<int>(h));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    rep(i, 0, w){
        rep(j, 0, h){
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}