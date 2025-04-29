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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int cnt = 0;
    rep(i, 0, n) cnt += a[i]%2;

    if(n == 1){
        cout << "Fennec" << endl;
    }else if(n == 2){
        cout << "Snuke" << endl;
    }else if(n == 3){
        if(cnt >= 1) cout << "Fennec" << endl;
        else cout << "Snuke" << endl;
    }else{
        if(cnt%2 == 1) cout << "Fennec" << endl;
        else cout << "Snuke" << endl;
    }
    return 0;
}