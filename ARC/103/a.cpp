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
    vector<int> v(n);
    vector<vector<int>> cnt(2, vector<int>(100005));
    rep(i, 0, n){
        cin >> v[i];
        cnt[i%2][v[i]]++;
    }

    int mx1 = 0, v1 = 0;
    int mx2 = 0;
    rep(i, 1, 100005){
        if(cnt[0][i] >= mx1){
            mx2 = mx1;
            mx1 = cnt[0][i], v1 = i;
        }
    }

    int ans = n;
    rep(i, 1, 100005){
        if(v1 == i){
            chmin(ans, n-(cnt[1][i]+mx2));
        }else{
            chmin(ans, n-(cnt[1][i]+mx1));
        }
    }
    cout << ans << endl;    
    return 0;
}