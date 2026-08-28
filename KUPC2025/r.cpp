#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, m; cin >> n >> m;
    {
        // 不可能か判定
        if((m%5)%2 == 0){
            if(m/5+(m%5)/2 > n){
                cout << "Impossible" << endl;
                return 0;
            }
        }else{
            if(m <= 5 || (m-5)/5+(m%5+5)/2 > n){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    {
        // 勝敗
        bool ok = false;
        if(m%2 == 0 && inr(1, m/2, n)) ok = true;
        if(m%5 == 0 && inr(1, m/5, n)) ok = true;
        if((m-n*2)%3 == 0 && inr(1, (m-n*2)/3, n)) ok = true;
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}