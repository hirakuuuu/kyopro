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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    if(k > (n+1)/2){
        cout << -1 << endl;
        return 0;
    }

    int c = 2*n, b = n+(n+1)/2-1;
    for(int a = 0; a <= n-1; a += 2){
        cout << k+a << ' ' << k+b << ' ' << k+c << endl;
        c++;
        b--;
        if(b < n) b += n;
    }
    for(int a = 1; a <= n-1; a += 2){
        cout << k+a << ' ' << k+b << ' ' << k+c << endl;
        c++;
        b--;
        if(b < n) b += n;
    }

    return 0;
}