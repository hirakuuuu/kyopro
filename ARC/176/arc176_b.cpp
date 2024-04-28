#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    vector<int> amari = {6, 2, 4, 8};
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        if(m == k+1){
            // 2^k で割ったあまり
            if(n < k){
                cout << amari[n%4] << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            if(n < m){
                cout << amari[n%4] << endl;
            }else{
                cout << amari[((n-k)%(m-k)+k)%4] << endl;
            }
        }
        // cout << ((1<<n)%((1<<m)-(1<<k)))%10 << endl;
    }
    
    return 0;
}