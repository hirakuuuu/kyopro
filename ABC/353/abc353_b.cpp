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
    int n, k; cin >> n >> k;
    int cnt = 0, rest = k;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        if(rest >= a[i]){
            rest -= a[i];
        }else{
            cnt++;
            rest = k-a[i];
        }
    }
    cnt++;
    cout << cnt << endl;
    
    return 0;
}