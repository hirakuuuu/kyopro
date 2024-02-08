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
// https://atcoder.jp/contests/arc171/tasks/arc171_a

int main(){
    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;
        bool ok = true;
        if(n < a) ok = false;
        if((n-a)*(min(n+1, (n-a)*2)/2) < b) ok = false;
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    
    return 0;
}