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
    int x; cin >> x;
    int q; cin >> q;
    multiset<int> sml, big;
    while(q--){
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        sml.insert(a);
        sml.insert(b);
        sml.insert(x);
        int y1 = *sml.rbegin();
        sml.erase(sml.find(y1));
        int y2 = *sml.rbegin();
        sml.erase(sml.find(y2));

        big.insert(y1);
        big.insert(y2);
        int y3 = *big.begin();
        big.erase(big.begin());
        x = y3;
        cout << x << endl;
    }
    
    return 0;
}