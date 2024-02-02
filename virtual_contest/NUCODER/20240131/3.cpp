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

ll f(ll a){
    if(a%4 == 0) return a;
    if(a%4 == 3) return 0;
    if(a%4 == 1) return 1;
    return a^1;
}

int main(){
    ll a, b; cin >> a >> b;
    if(a == 0) cout << f(b) << endl;
    else cout << (f(a-1)^f(b)) << endl;

    
    return 0;
}