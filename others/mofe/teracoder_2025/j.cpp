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
    auto my_sqrt = [](int x)->int{ // sqrtの誤差がないバージョン
        int res = (int)sqrt(x);
        if((ll)res*res > x) res--;
        if((ll)(res+1)*(res+1) <= x) res++;
        return res;
    };

    int m, r; cin >> m >> r;
    vector<int> s(r);
    rep(i, 0, r) cin >> s[i];
    sort(s.begin(), s.end());

    auto check = [&](int i) -> bool {
        int tot = 0;
        rep(j, 0, r){
            tot += my_sqrt(s[i]+s[j]);
        }
        return tot <= m;
    };

    if(!check(0)){
        cout << -1 << endl;
        return 0;
    }

    int ok = 0, ng = r;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    int ans = 0;
    rep(j, 0, r){
        ans += my_sqrt(s[ok]+s[j]);
    }
    cout << ans << endl;

    return 0;
}