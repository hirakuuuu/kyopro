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
// https://atcoder.jp/contests/arc161/tasks/arc161_d

int main(){
    ll n, d; cin >> n >> d;

    if(n < 3 || n*(n-1)/2 < n*d){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    rep(i, 0, n){
        rep(j, 1, d+1){
            cout << i+1 << ' ' << ((i+j)%n)+1 << endl;
        }
    }




    
    return 0;
}