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
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    
    int sum_a = 0, sum_b = 0;
    rep(i, 0, n){
        sum_a += a[i];
        sum_b += b[i];
    }

    if(sum_a != sum_b){
        cout << "No" << endl;
        return 0;
    }
    if(n == 2){
        if(a == b){
            cout << "Yes" << endl;
            cout << 0 << endl;
        }else if(a[1]-1 == b[0] && a[0]+1 == b[1]){
            cout << "Yes" << endl;
            cout << 1 << endl;
            cout << 1 << ' ' << 2 << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }

    

    return 0;
}