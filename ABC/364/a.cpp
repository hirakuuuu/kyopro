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
    
    int n; cin >> n;
    string pre = "salty";
    rep(i, 0, n){
        string tmp; cin >> tmp;
        if(pre == tmp && pre == "sweet" && i != n-1){
            cout << "No" << endl;
            return 0;
        }
        pre = tmp;
    }
    cout << "Yes" << endl;
    return 0;
}