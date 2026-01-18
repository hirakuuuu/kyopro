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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        sort(a.begin(), a.end());

        bool same = true;
        rep(i, 1, n){
            if(a[i] != a[0]) same = false;
        }
        if(same){
            cout << 0 << endl;
            continue;
        }

        vector<ll> acc(n+1);
        rep(i, 0, n) acc[i+1] = acc[i]+a[i];

        int ans = 1;
        ll sum = a[0];
        rep(i, 1, n){
            ll mi = abs(sum-a[i]*i);
            // cout << i << ' ' << mi << endl;
            ll ok = i, ng = n+1;
            while(ng-ok > 1){
                int mid = (ok+ng)/2;
                // cout << mid << ' ' << i << ' ' << acc[mid]-acc[i]-a[i]*(mid-i) << endl;
                if(acc[mid]-acc[i]-a[i]*(mid-i) < mi) ok = mid;
                else ng = mid;
            }
            cout << ok << endl;
            chmax(ans, ok-i);
            sum += a[i];
        }
        cout << ans << endl;


    }
    
    return 0;
}