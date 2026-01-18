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
    int n, w, h; cin >> n >> w >> h;
    string s; cin >> s;
    vector<string> ans(w);
    int r = 0;
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && s[j] == 'o'){
            j++;
        }
        rep(k, 0, j-i) ans[r] += 'o';
        rep(k, j-i, h) ans[r] += 'x';
        r++;
        i = j+1;
    }
    while(r < w){
        ans[r] = string(h, 'x');
        r++;
    }

    rrep(i, h-1, 0){
        rep(j, 0, w){
            cout << ans[j][i];
        }
        cout << endl;
    }
    return 0;
}