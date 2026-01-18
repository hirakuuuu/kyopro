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
    string s; cin >> s;
    int n = (int)s.size();
    double ans = 0.0;
    rep(i, 0, n){
        rep(j, i+1, n+1){
            string tmp = s.substr(i, j-i);
            if(tmp.size() <= 2) continue;
            if(tmp[0] == 't' && tmp.back() == 't'){
                double x = 0;
                for(auto tt: tmp){
                    if(tt == 't') x++;
                }
                chmax(ans, (x-2.0)/(tmp.size()-2));
            }
        }
    }
    
    cout << setprecision(20) << ans << endl;
    return 0;
}