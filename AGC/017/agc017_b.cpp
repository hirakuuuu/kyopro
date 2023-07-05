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
// https://atcoder.jp/contests/agc017/tasks/agc017_b

int main(){
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    bool ok = false;
    for(ll i = 0; i < n; i++){
        ll tmp = a+(2*i-n+1)*c;
        if(tmp <= b && b-tmp <= i*(d-c)){
            ok = true;
            break;
        }else if(tmp > b && tmp-b <= (n-1-i)*(d-c)){
            ok = true;
            break;
        }
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}