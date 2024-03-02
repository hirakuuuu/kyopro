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
// https://atcoder.jp/contests/abc342/tasks/abc342_c

int main(){
    int n;cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    string abc;
    rep(i, 0, 26){
        abc += (char)'a'+i;
    }
    while(q--){
        char c, d; cin >> c >> d;
        rep(i, 0, 26){
            if(abc[i] == c){
                abc[i] = d;
            }
        }
    }
    rep(i, 0, n){
        cout << abc[s[i]-'a'];
    }
    cout << endl;
    
    return 0;
}