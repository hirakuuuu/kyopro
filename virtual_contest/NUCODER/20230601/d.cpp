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

ll f(ll a){
    if(a%2 == 0){
        return ((a/2)%2 ? 1 : 0)^a;
    }else{
        return (((a+1)/2)%2 ? 1 : 0);
    }
}

int main(){
    ll a, b; cin >> a >> b;
    cout << (f(a-1)^f(b)) << endl;


    
    return 0;
}