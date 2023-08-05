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
// https://atcoder.jp/contests/abc101/tasks/arc099_b

ll digit_sum(ll n){
    ll sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    ll k; cin >> k;
    ll tmp = 1, inc = 1;
    while(k--){
        cout << tmp << endl;
        if((tmp+1)%(inc*10) == 0 && digit_sum(tmp+inc) * inc <= tmp + inc){
            inc *= 10;
        }
        tmp += inc;
    }
    
    return 0;
}