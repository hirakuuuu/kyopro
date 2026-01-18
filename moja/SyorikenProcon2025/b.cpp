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
    int x; cin >> x;
    
    vector<int> t = {0, 1, 10, 30, 70, 100, IINF};
    int p = upper_bound(t.begin(), t.end(), n)-t.begin()-1;
    int q = upper_bound(t.begin(), t.end(), n+x)-t.begin()-1;
    if(p != q){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}