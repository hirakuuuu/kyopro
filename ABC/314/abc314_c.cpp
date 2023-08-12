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
// https://atcoder.jp/contests/abc314/tasks/abc314_c

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> c(n);
    vector<vector<int>> p(m);
    rep(i, 0, n){
        cin >> c[i];
        c[i]--;
        p[c[i]].push_back(i);
    }

    vector<char> ans(n);
    rep(i, 0, m){
        int tmp = p[i].size();
        rep(j, 0, tmp){
            ans[p[i][(j+1)%tmp]] = s[p[i][j]];
        }
    }

    for(auto aa: ans){
        cout << aa;
    }
    cout << endl;


    
    return 0;
}