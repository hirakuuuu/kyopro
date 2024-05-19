#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        vector<int> a(3);
        rep(i, 0, 3) cin >> a[i];
        if(a[0] > a[1]) swap(a[0], a[1]);
        if(a[1] != a[2] && a[1]+1 != a[2]){
            cout << 0 << endl;
            continue;
        }
        vector<mint> ten(3);
        rep(i, 0, 3) ten[i] = mint(10).pow(a[i]);

        mint ans = 0;
        if(a[1] == a[2]){
            mint l, r;
            if(a[0] == a[1]){
                l = 1;
                r = (ten[0]/10)*8;
            }else{
                l = (ten[1]-ten[0])-(ten[1]/10)+1;
                r = (ten[1]/10)*9-(ten[0]/10);
            }
            // cout << l.val() << ' ' << r.val() << ' ' << ans.val() << endl;
            ans += (r+l)*(r-l+1)/2;
        }else if(a[1]+1 == a[2]){
            mint l, r;
            if(a[0] == a[1]){
                ans += (ten[0]/10-1)*(ten[0]/10)*9;
                l = ten[0]/10;
                r = (ten[0]/10)*9;
            }else{
                l = ten[0]/10;
                r = ten[0]-1;
            }
            // cout << l.val() << ' ' << r.val() << ' ' << ans.val() << endl;
            ans += (r+l)*(r-l+1)/2;

        }
        cout << ans.val() << endl;

    }
    
    return 0;
}