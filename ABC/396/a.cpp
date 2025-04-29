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
    int pre1 = -1, pre2 = -1;
    cin >> pre1 >> pre2;
    bool ok = false;
    rep(i, 0, n-2){
        int tmp; cin >> tmp;
        if(pre1 == tmp && pre2 == tmp){
            ok = true;
        }
        pre1 = pre2;
        pre2 = tmp;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}