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
// 

int main(){
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector<vector<int>> taka(n, vector<int>(n)), aoki(n, vector<int>(n));
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        taka[a][b] = taka[b][a] = 1;
    }
    rep(i, 0, m){
        int c, d; cin >> c >> d;
        c--, d--;
        aoki[c][d] = aoki[d][c] = 1;
    }
    iota(p.begin(), p.end(), 0);
    do{
        int cnt = 0;
        rep(i, 0, n){
            rep(j, i+1, n){
                if(taka[i][j] && aoki[p[i]][p[j]]) cnt++;
            }
        }
        if(cnt == m){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(p.begin(), p.end()));
    cout << "No" << endl;
    return 0;
}