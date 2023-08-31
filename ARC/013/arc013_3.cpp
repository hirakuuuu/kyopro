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
// https://atcoder.jp/contests/arc013/tasks/arc013_3

int main(){
    int n; cin >> n;
    int a = 0;
    rep(i, 0, n){
        vector<int> s(3);
        rep(j, 0, 3) cin >> s[j];
        int m; cin >> m;
        vector<int> min_s(3, IINF), max_s(3), h(3);
        rep(j, 0, m){
            rep(k, 0, 3){
                cin >> h[k];
                chmin(min_s[k], h[k]);
                chmax(max_s[k], h[k]);
            }
        }

        rep(k, 0, 3){
            a ^= min_s[k];
            a ^= s[k]-1-max_s[k];
        }
    }

    if(a == 0) cout << "LOSE" << endl;
    else cout << "WIN" << endl;
    
    return 0;
}