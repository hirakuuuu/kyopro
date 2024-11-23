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
    string s; cin >> s;

    vector<vector<int>> cnt(n+1, vector<int>(3));
    rep(i, 1, n+1){
        cnt[i][1] = cnt[i-1][1];
        if(s[i-1] == '1') cnt[i][1]++;
        else cnt[i][1] = 0;
    }
    rrep(i, n-1, 0){
        cnt[i][2] = cnt[i+1][2];
        if(s[i] == '2') cnt[i][2]++;
        else cnt[i][2] = 0;
    }

    int ans = 0;
    rep(i, 0, n){
        if(s[i] == '/'){
            chmax(ans, 2*min(cnt[i][1], cnt[i+1][2])+1);
        }
    }
    cout << ans << endl;
    return 0;
}