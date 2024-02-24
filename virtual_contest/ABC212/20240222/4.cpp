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
// https://atcoder.jp/contests/abc252/tasks/abc252_g

int main(){
    int q; cin >> q;
    multiset<ll> ms;
    ll sum = 0;
    while(q--){
        int p; cin >> p;
        if(p == 1){
            ll x; cin >> x;
            ms.insert(x-sum);
        }else if(p == 2){
            ll x; cin >> x;
            sum += x;
        }else{
            cout << *ms.begin()+sum << endl;
            ms.erase(ms.begin());
        }
    }
    return 0;
}