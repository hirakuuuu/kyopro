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
    int n, m, k; cin >> n >> m >> k;
    vector<int> c(m);
    vector<int> a(m);
    vector<char> r(m);
    rep(i, 0, m){
        cin >> c[i];
        rep(j, 0, c[i]){
            int A; cin >> A;
            A--;
            a[i] += (1<<A);
        }
        cin >> r[i];
    }
    int ans = 0;
    rep(i, 0, 1<<n){
        bool ok = true;
        rep(j, 0, m){
            if(r[j] == 'o'){
                if(__popcount(i&a[j]) >= k) continue;
                ok = false;
            }else{
                if(__popcount(i&a[j]) < k) continue;
                ok = false;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;

    
    return 0;
}