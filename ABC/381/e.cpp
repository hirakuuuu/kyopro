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

    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<vector<int>> acc(n+1, vector<int>(3));
    vector<int> p;
    rep(i, 1, n+1){
        if(s[i-1] == '/'){
            p.push_back(i-1);
        }
        rep(j, 0, 3){
            acc[i][j] = acc[i-1][j];
            if(j == 0){
                if(s[i-1] == '/') acc[i][j]++;
            }else{
                if(s[i-1]-'0' == j) acc[i][j]++;
            }
        }
    }

    while(q--){
        int l, r; cin >> l >> r; l--;

        if(acc[r][0]-acc[l][0] == 0){
            cout << 0 << endl;
            continue;
        }

        int ok = lower_bound(p.begin(), p.end(), l)-p.begin();
        int ng = lower_bound(p.begin(), p.end(), r)-p.begin();
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            // p[mid] について、(左の1の個数) - (右の2の個数) <= 0 を調べる
            int cnt1 = acc[p[mid]+1][1]-acc[l][1];
            int cnt2 = acc[r][2]-acc[p[mid]+1][2];
            if(cnt1-cnt2 <= 0) ok = mid;
            else ng = mid;
        }
        // cout << p[ok] << ' ' << p[ng] << endl;

        int ans = min(acc[p[ok]+1][1]-acc[l][1], acc[r][2]-acc[p[ok]+1][2]);
        if(p[ng] < r){
            chmax(ans, min(acc[p[ng]+1][1]-acc[l][1], acc[r][2]-acc[p[ng]+1][2]));
        }
        cout << 2*ans+1 << endl;
    }
    
    return 0;
}