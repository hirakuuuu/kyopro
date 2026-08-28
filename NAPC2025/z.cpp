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
    vector<int> c(n), s(n), z(n);
    vector<int> x(n), y(n);
    rep(i, 0, n){
        cin >> c[i] >> s[i] >> z[i];
        x[i] = c[i]-1;
        y[i] = s[i]-z[i];
    }

    rep(i, 0, n-1){
        if((x[i] == x[i+1] && y[i] < y[i+1]) || x[i] > x[i+1]) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}