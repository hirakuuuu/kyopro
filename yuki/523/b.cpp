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
    int M = 30;
    auto query = [&](int x) -> int{
        assert(M >= 1);
        cout << x << endl;
        M--;

        int r; cin >> r;
        return r;
    };

    int ok = 0, ng = 1e9+1;
    while(ng-ok > 1 && M >= 1){
        int mid = (ok+ng)/2;
        if(query(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}