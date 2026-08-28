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
        vector<ll> a(3);
        rep(i, 0, 3){
            cin >> a[i];
        }

        ll ok = 0, ng = 1LL<<40;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            vector<ll> b = a;
            bool flag = true;
            rep(i, 0, 3){
                b[i] -= mid;
                if(b[i] < 0) flag = false;
            }
            if(!flag){
                ng = mid;
                continue;
            }

            ll tmp = 0;
            rep(i, 0, 3){
                ll x = max(0LL, min(b[i], (b[(i+1)%3]-b[(i+2)%3]/2)/2));
                ll y = max(0LL, min(b[i], (b[(i+1)%3]-b[(i+2)%3]/2)/2));
                chmax(now, mid+min(b[i], (b[(i+1)%3]-b[])))
            }
        }
        ll ans = (mi/3)*3;
        rep(i, 0, 3) a[i] -= (mi/3)*3;

        rep(i, 0, 3){
            cout << a[i] << ' ';
        }
        cout << endl;

        if(a[mid] == 0){
            ans += max(0LL, min(a[(mid+1)%3], a[(mid+2)%3]-1));
        }else if(a[mid] == 1){
            ll now1 = ans, now2 = ans;
            if(a[(mid+1)%3] >= 2) now1 += 1+max(0LL, min(a[(mid+1)%3]-2, a[(mid+2)%3]-1));
            now2 += max(0LL, min(a[(mid+1)%3], a[(mid+2)%3]-1));
            chmax(ans, max(now1, now2));
        }else{
            ll now1 = ans, now2 = ans, now3 = ans;
            if(a[(mid+1)%3] >= 2) now1 += 1+max(0LL, min(a[(mid+1)%3]-2, a[(mid+2)%3]-1));
            if(a[(mid+1)%3] >= 4) now2 += 2+max(0LL, min(a[(mid+1)%3]-4, a[(mid+2)%3]-1));
            now3 += max(0LL, min(a[(mid+1)%3], a[(mid+2)%3]-1));
            chmax(ans, max({now1, now2, now3}));
        }

        cout << ans << endl;
    }
    
    return 0;
}