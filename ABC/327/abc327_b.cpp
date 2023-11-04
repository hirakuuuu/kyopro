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
// https://atcoder.jp/contests/abc327/tasks/abc327_b

int main(){

    ll b; cin >> b;
    if(b == 1){
        cout << 1 << endl;
        return 0;
    }
    ll tmp = 2;
    while(tmp < 100){
        ll a = b, cnt = 0;
        while(a%tmp == 0){
            a /= tmp;
            cnt++;
        }
        if(a == 1 && cnt == tmp){
            cout << tmp << endl;
            return 0;
        }
        tmp++;
    }
    cout << -1 << endl;

    

    
    return 0;
}