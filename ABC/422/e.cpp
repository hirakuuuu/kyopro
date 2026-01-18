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
    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
    }

    rep(_, 0, 100){
        int a = rand()%n, b = rand()%n;
        while(a == b) b = rand()%n;
        
        int cnt = 0;
        rep(i, 0, n){
            if((x[a]-x[b])*y[i]-(y[a]-y[b])*x[i] == -x[b]*y[a]+y[b]*x[a]){
                cnt++;
            }
        }
        if(cnt > n/2){
            cout << "Yes" << endl;
            cout << -(y[a]-y[b]) << ' ' << (x[a]-x[b]) << ' ' << x[b]*y[a]-y[b]*x[a] << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}