#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    set<int> s;
    rep(i, 0, k) s.insert(p[i]);
    cout << *s.begin() << endl;
    rep(i, k, n){
        s.insert(p[i]);
        s.erase(s.begin());
        cout << *s.begin() << endl;
    }
    return 0;
}