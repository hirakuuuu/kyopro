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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int need = abs(a[0])-1;
    rep(i, 0, a.size()-1) need += abs(a[i]-a[i+1])-1; 
    int cnt = n-a.size();
    int ans = n/2;
    rrep(i, a.size()-1, 0){
        // cout << i << ' ' << a[i] << ' ' << cnt << ' ' << need << endl;
        if(2*need <= cnt){
            chmax(ans, a[i]+(cnt-2*need)/2);
        }
        if(i > 0) need -= abs(a[i]-a[i-1])-1;
        else need += abs(a[i])-1;
        cnt++;
    }

    cout << ans << endl;

    
    return 0;
}