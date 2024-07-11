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
    int n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i, 0, n) cin >> l[i] >> r[i];
    vector<ll> a(n, -1);
    ll L = l[0], R = r[0];
    rep(i, 1, n){
        if(max(L, l[i]) > min(R, r[i])){
            if(r[i] < L) a[0] = L;
            else a[0] = R;
            break;
        }
        chmax(L, l[i]);
        chmin(R, r[i]);
    }
    if(a[0] == -1) a[0] = L;

    rep(i, 1, n){
        // a[i-1] -> [l[i], r[i]] に差が最小になるように遷移する
        if(a[i-1] <= l[i]) a[i] = l[i];
        else if(r[i] <= a[i-1]) a[i] = r[i];
        else a[i] = a[i-1];
    }

    // 辞書順最小になるように変える
    rrep(i, n-1, 0){
        if(i == n-1){
            if(a[i-1] <= a[i]){
                if(l[i] <= a[i-1]) a[i] = a[i-1];
                else a[i] = l[i];
            }
        }else if(i == 0){
            if(a[i+1] <= a[i]){
                if(l[i] <= a[i+1]) a[i] = a[i+1];
                else a[i] = l[i];
            }
        }else{
            if(a[i-1] <= a[i] && a[i] <= a[i+1]){
                if(l[i] <= a[i-1]) a[i] = a[i-1];
                else a[i] = l[i];
            }else if(a[i+1] <= a[i] && a[i] <= a[i-1]){
                if(l[i] <= a[i+1]) a[i] = a[i+1];
                else a[i] = l[i];
            }
        }
    }

    rep(i, 0, n) cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}