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
// https://atcoder.jp/contests/abc335/tasks/abc335_c

int main(){
    int n, q; cin >> n >> q;
    vector<pair<int, int>> d(n);
    rep(i, 0, n){
        d[n-i-1] = {i+1, 0};
    }
    int offset = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    string dir = "LDRU";
    while(q--){
        int t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            rep(i, 0, 4){
                if(c == dir[i]){
                    d.push_back({d.back().first+dx[i], d.back().second+dy[i]});
                    offset++;
                }
            }
        }else if(t == 2){
            int p; cin >> p;
            p--;
            p = (n-p-1)+offset;
            cout << d[p].first << ' ' << d[p].second << endl;
        }
    }
    
    return 0;
}