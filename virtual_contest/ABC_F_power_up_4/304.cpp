#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> y = {1};
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            y.push_back(i);
            if(n/i != i) y.push_back(n/i);
        }
    }
    sort(y.begin(), y.end());

    mint ans = 0;
    vector<mint> cnt(n);
    for(auto yy: y){
        vector<bool> same(yy, true);
        rep(i, 0, n){
            if(s[i%yy] != s[i]) same[i%yy] = false;
        }

        mint tmp = 1;
        rep(i, 0, yy){
            if(same[i] && s[i] == '#') tmp *= 2;
        }
        cnt[yy] += tmp;
        ans += cnt[yy];
        // cout << yy << ' ' << ' ' << tmp.val() << ' ' << cnt[yy].val() << endl;

        for(int i = yy+yy; i < n; i += yy){
            // cout << i << endl;
            cnt[i] -= cnt[yy];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}