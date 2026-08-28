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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        ll b; cin >> b;
        if(b == 0) break;

        b *= 2;
        vector<int> yakusu;
        for(ll y = 1; y*y <= b; y++){
            if(b%y == 0){
                yakusu.push_back(y);
                if(b/y != y) yakusu.push_back(b/y);
            }
        }
        sort(yakusu.begin(), yakusu.end());

        ll ans = 0, len = 0;
        for(auto y: yakusu){
            ll c = b/y;
            if((c-y-1) >= 0 && (c-y-1)%2 == 0){
                ans = (c-y-1)/2+1;
                len = y;
            }
        }
        cout << ans << ' ' << len << endl;
    }
    
    return 0;
}