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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    if(n%2 == 0){
        sort(a.begin(), a.end());
        ll ans = 0;
        rep(i, 0, n/2) ans -= a[i];
        rep(i, n/2, n) ans += a[i];
        cout << ans << endl;
    }else{
        vector<ll> acc_l(n+1), acc_r(n+1);
        {
            priority_queue<ll> mi;
            priority_queue<ll, vector<ll>, greater<ll>> mx;
            for(int i = 2; i < n; i += 2){
                // [0, i) に操作を行ったときの最大値
                acc_l[i] = acc_l[i-2];
                if(mx.empty() || mx.top() >= a[i-2]){
                    mi.push(a[i-2]);
                    acc_l[i] -= a[i-2];
                }else{
                    mi.push(mx.top());
                    acc_l[i] -= 2*mx.top();
                    mx.pop();
                    mx.push(a[i-2]);
                    acc_l[i] += a[i-2];
                }

                if(mi.top() < a[i-1]){
                    mx.push(a[i-1]);
                    acc_l[i] += a[i-1];
                }else{
                    mx.push(mi.top());
                    acc_l[i] += 2*mi.top();
                    mi.pop();
                    mi.push(a[i-1]);
                    acc_l[i] -= a[i-1];
                }
            }
        }

        {
            priority_queue<ll> mi;
            priority_queue<ll, vector<ll>, greater<ll>> mx;
            for(int i = n-3; i >= 0; i -= 2){
                // (i, n-1] に操作を行ったときの最大値
                acc_r[i] = acc_r[i+2];
                if(mx.empty() || mx.top() >= a[i+2]){
                    mi.push(a[i+2]);
                    acc_r[i] -= a[i+2];
                }else{
                    mi.push(mx.top());
                    acc_r[i] -= 2*mx.top();
                    mx.pop();
                    mx.push(a[i+2]);
                    acc_r[i] += a[i+2];
                }

                if(mi.top() < a[i+1]){
                    mx.push(a[i+1]);
                    acc_r[i] += a[i+1];
                }else{
                    mx.push(mi.top());
                    acc_r[i] += 2*mi.top();
                    mi.pop();
                    mi.push(a[i+1]);
                    acc_r[i] -= a[i+1];
                }
            }
        }

        ll ans = 0;
        for(int i = 0; i < n; i += 2){
            // cout << i << ' ' << acc_l[i]+acc_r[i] << endl;
            chmax(ans, acc_l[i]+acc_r[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}