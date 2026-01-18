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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> c(n+1);
        rep(i, 0, n+1) cin >> c[i];
        rep(i, 1, n+1) c[i]--;
        string ans = string(n, 'R');
        bool ok = true;
        rrep(i, n, 1){
            // cout << c[i] << ' ' << c[i-1] << ' ' << (c[i] > c[i-1]) << endl;
            if(c[i-1] <= c[i]){
                ok = false;
                break;
            }
            // cout << i << ' ' << c[i] << ' ' << c[i-1] << endl;
            while(c[i]){
                ans += 'L', ans += 'R';
                c[i]--, c[i-1]--;
            }
            ans += 'L';
            c[i-1]--;
        }
        if(c[0] > 0) ok = false;

        if(ok){
            reverse(ans.begin(), ans.end());
            for(auto aa: ans){
                if(aa == 'L') cout << 'R';
                else cout << 'L';
            }
            cout << endl;
        }else{
            cout << "Impossible" << endl;
        }

        
    }
    return 0;
}