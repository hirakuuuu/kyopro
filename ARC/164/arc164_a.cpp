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
// https://atcoder.jp/contests/arc164/tasks/arc164_a

int main(){
    int T; cin >> T;
    while(T--){
        ll n, k; cin >> n >> k;
        ll cnt = 0, m = n, l = 1;
        while(m){
            cnt += (m%(3*l))/l;
            l *= 3;
            m -= m%l;
        }
        if(cnt <= k && (k-cnt)%2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}