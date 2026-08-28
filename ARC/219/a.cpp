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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
    }
    if(m <= 20){
        if(n == 1<<m){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    set<int> t;
    rep(i, 0, n){
        int cnt = 0;
        rep(j, max(0, m-20), m){
            cnt <<= 1;
            cnt += s[i][j]-'0';
        }
        t.insert(cnt);
    }

    rep(i, 0, 1<<20){
        if(t.count(i)) continue;
        string ans;
        rep(j, 0, 20){
            ans += (char)('1'-(i>>j&1));
        }
        // reverse(ans.begin(), ans.end());
        while(ans.size() < m) ans += '1';
        while(ans.size() > m) ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        break;
    }

    
    return 0;
}