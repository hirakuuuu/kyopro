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
    int a, b, c; cin >> a >> b >> c;
    int s = a+b+c;
    if(a == b && b == c){
        cout << "Yes" << endl;
    }else if(s%2 == 0 && s/2 == max({a, b, c})){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}