#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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

int main(){
    ll n; cin >> n;
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    // 全部同じ
    for(ll a = 1; a*a*a <= n; a++){
        ans1++;
    }
    // a=b
    for(ll a = 1; a*a*a <= n; a++){
        ans2 += max(0LL, n/(a*a)-a);
    }
    // b=c
    for(ll b = 1; b*b <= n; b++){
        ans2 += min(b-1, n/(b*b));
    }
    // すべて異なる
    for(ll a = 1; a*a*a <= n; a++){
        for(ll b = a+1; b*b <= n; b++){
            if(n/(a*b) <= b) break;
            ans3 += n/(a*b)-b;
        }
    }
    cout << ans1+ans2+ans3 << endl;

    return 0;
}