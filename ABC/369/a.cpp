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
    int a, b; cin >> a >> b;
    set<int> s;
    s.insert(a+(b-a)*2);
    s.insert(b+(a-b)*2);
    if((a-b)%2 == 0){
        s.insert(a+(b-a)/2);
        s.insert(b+(a-b)/2);
    }
    cout << s.size() << endl;
    
    return 0;
}