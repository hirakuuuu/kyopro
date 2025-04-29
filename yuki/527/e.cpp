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
    int h; cin >> h;
    vector<pair<int, int>> event;
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        event.push_back({a, 0});
        event.push_back({b, 1});
    }
    sort(event.begin(), event.end());

    int num = 0, ans = 0;
    rep(i, 0, 2*n){
        auto [t, p] = event[i];
        if(p == 0){
            num++;
        }else{
            num--;
        }
        chmax(ans, num);
    }
    cout << ans << endl;
    return 0;
}