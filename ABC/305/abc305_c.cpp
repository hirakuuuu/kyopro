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
// https://atcoder.jp/contests/abc305/tasks/abc305_c

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2, '.'));
    rep(i, 1, h+1){
        rep(j, 1, w+1) cin >> s[i][j];
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(s[i][j] == '#') continue;
            int cnt = 0;
            rep(k, 0, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(s[ni][nj] == '#') cnt++;
            }
            if(cnt >= 2){
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
    return 0;
}