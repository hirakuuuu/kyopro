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
// https://atcoder.jp/contests/arc059/tasks/arc059_b

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> pos(26);
    rep(i, 0, n){
        pos[s[i]-'a'].push_back(i+1);
    }

    rep(i, 0, 26){
        if(pos[i].size() < 2) continue;
        rep(j, 0, pos[i].size()-1){
            if(pos[i][j+1]-pos[i][j] <= 2){
                cout << pos[i][j] << ' ' << pos[i][j+1] << endl;
                return 0;
            }
        }
    }

    cout << -1 << ' ' << -1 << endl;
    return 0;
}