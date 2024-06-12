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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    if(k > 0){
        sort(a.begin(), a.end());
        vector<ll> acc(n+1);
        rep(i, 1, n+1) acc[i] = acc[i-1]+a[i-1];
        int l = 0;
        while(l <= n && acc[l] < k) l++;
        rep(i, l, n+1){
            if(acc[i] < k){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        rep(i, 0, n) cout << a[i] << ' ';
        cout << endl;
    }else{
        sort(a.rbegin(), a.rend());
        vector<ll> acc(n+1);
        rep(i, 1, n+1) acc[i] = acc[i-1]+a[i-1];
        rep(i, 1, n+1){
            if(acc[i] < k){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        rep(i, 0, n) cout << a[i] << ' ';
        cout << endl;
    }

    
    return 0;
}