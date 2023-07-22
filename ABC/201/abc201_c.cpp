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
// https://atcoder.jp/contests/abc201/tasks/abc201_c

int main(){
    string s; cin >> s;
    int cnt_o = 0;
    rep(i, 0, s.size()) cnt_o += s[i] == 'o';

    int ans = 0;
    rep(i, 0, 10){
        rep(j, 0, 10){
            rep(k, 0, 10){
                rep(l, 0, 10){
                    int f = 0;
                    rep(t, 0, 10){
                        if((t == i || t == j || t == k || t == l) && s[t] == 'x') f -= 10000000;
                        if((t == i || t == j || t == k || t == l) && s[t] == 'o') f++;
                    }
                    if(f == cnt_o) ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}