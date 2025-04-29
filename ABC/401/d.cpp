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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t = s;

    vector<vector<int>> dp_l(n+1, vector<int>(2));
    vector<vector<int>> mi_l(n+1, vector<int>(2));
    rep(i, 0, n){
        if(s[i] == 'o'){
            dp_l[i+1][0] = 0;
            dp_l[i+1][1] = dp_l[i][0]+1;
        }else if(s[i] == '.'){
            dp_l[i+1][0] = max(dp_l[i][0], dp_l[i][1]);
            dp_l[i+1][1] = 0;
        }else{
            dp_l[i+1][0] = max(dp_l[i][0], dp_l[i][1]);
            dp_l[i+1][1] = dp_l[i][0]+1;
        }
    }

    rep(i, 0, n){
        if(s[i] == 'o'){
            mi_l[i+1][0] = IINF;
            mi_l[i+1][1] = mi_l[i][0]+1;
        }else if(s[i] == '.'){
            mi_l[i+1][0] = min(mi_l[i][0], mi_l[i][1]);
            mi_l[i+1][1] = IINF;
        }else{
            mi_l[i+1][0] = min(mi_l[i][0], mi_l[i][1]);
            mi_l[i+1][1] = mi_l[i][0]+1;
        }
    }

    vector<vector<int>> dp_r(n+1, vector<int>(2));
    vector<vector<int>> mi_r(n+1, vector<int>(2));
    rrep(i, n, 1){
        if(s[i-1] == 'o'){
            dp_r[i-1][0] = 0;
            dp_r[i-1][1] = dp_r[i][0]+1;
        }else if(s[i-1] == '.'){
            dp_r[i-1][0] = max(dp_r[i][0], dp_r[i][1]);
            dp_r[i-1][1] = 0;
        }else{
            dp_r[i-1][0] = max(dp_r[i][0], dp_r[i][1]);
            dp_r[i-1][1] = dp_r[i][0]+1;
        }
    }
    rrep(i, n, 1){
        if(s[i-1] == 'o'){
            mi_r[i-1][0] = IINF;
            mi_r[i-1][1] = mi_r[i][0]+1;
        }else if(s[i-1] == '.'){
            mi_r[i-1][0] = min(mi_r[i][0], mi_r[i][1]);
            mi_r[i-1][1] = IINF;
        }else{
            mi_r[i-1][0] = min(mi_r[i][0], mi_r[i][1]);
            mi_r[i-1][1] = mi_r[i][0]+1;
        }
    }

    rep(i, 0, n){
        if(t[i] == '?'){
            bool ok_o = false, ok_d = false;
            // o にできるか
            if((i == 0 || s[i-1] != 'o') && (i == n-1 || s[i+1] != 'o')
             && dp_l[i][0]+dp_r[i+1][0] >= k-1
             && mi_l[i][0]+mi_r[i+1][0] <= k-1) ok_o = true;
            // . にできるか
            if(max(dp_l[i][0], dp_l[i][1])+max(dp_r[i+1][0], dp_r[i+1][1]) >= k
            && min(mi_l[i][0], mi_l[i][1])+min(mi_r[i+1][0], mi_r[i+1][1]) <= k) ok_d = true;
            // cout << ok_o << ' ' << ok_d << endl;
            assert(ok_o || ok_d);
            if(ok_o && !ok_d) t[i] = 'o';
            if(!ok_o && ok_d) t[i] = '.';
        }
    }
    cout << t << endl;
    return 0;
}