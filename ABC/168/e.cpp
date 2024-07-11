#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        if(a[i] != 0 && b[i] != 0){
            ll g = abs(gcd(a[i], b[i]));
            a[i] /= g;
            b[i] /= g;
        }else if(a[i] != 0){
            a[i] = 1;
        }else if(b[i] != 0){
            b[i] = -1;
        }
        if(a[i] < 0){
            a[i] = -a[i];
            b[i] = -b[i];
        }
    }

    int zab = 0;
    map<pair<ll, ll>, int> cnt;
    rep(i, 0, n){
        if(a[i] == 0 && b[i] == 0){
            zab++;
        }else{
            cnt[{a[i], b[i]}]++;
        }
    }

    // (0, b) (a, 0)
    map<pair<ll, ll>, bool> seen;
    mint sum = 1;
    rep(i, 0, n){
        if(a[i] != 0 || b[i] != 0){
            if(seen[{a[i], b[i]}]) continue;
            if(b[i] < 0){
                seen[{a[i], b[i]}] = seen[{-b[i], a[i]}] = true;
                int c1 = cnt[{a[i], b[i]}], c2 = cnt[{-b[i], a[i]}];
                sum *= (mint(2).pow(c1+c2)-(mint(2).pow(c1)-1)*(mint(2).pow(c2)-1));
            }else{
                seen[{a[i], b[i]}] = seen[{b[i], -a[i]}] = true;
                int c1 = cnt[{a[i], b[i]}], c2 = cnt[{b[i], -a[i]}];
                sum *= (mint(2).pow(c1+c2)-(mint(2).pow(c1)-1)*(mint(2).pow(c2)-1));
            }
        }
    }
    sum -= 1;
    mint ans = sum+zab;
    cout << ans.val() << endl;
    return 0;
}