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
    if(n%2 == 0){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<int> p;
    for(int i = 1; i <= n; i += 2){
        p.push_back(i);
    }
    for(int i = 2; i <= n; i += 2){
        p.push_back(i);
    }
    rep(i, 0, n){
        cout << p[i] << ' ';
    }
    cout << endl;
    rep(i, 0, n){
        cout << ((n+3)/2+i)-p[i] << ' ';
    }
    cout << endl;
   
    return 0;
}