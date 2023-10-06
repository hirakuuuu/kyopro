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
// https://atcoder.jp/contests/abc258/tasks/abc258_g

int main(){
    int n; cin >> n;
    vector<bitset<3005>> a(n);
    rep(i, 0, n){
        rep(j, 0, n){
            char c; cin >> c;
            if(c == '1'){
                a[i].set(j);
            }
        }
    }

    ll cnt = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            if(a[i][j]){
                cnt += (a[i] & a[j]).count();
            }
        }
    }

    cout << cnt/3 << endl;


    
    return 0;
}