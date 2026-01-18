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

    int ans = 0;
    vector<vector<int>> pos(4);
    vector<int> score = {30, 10, 3, 1};
    vector<int> sz = {4, 3, 2, 1};
    rep(i, 0, n){
        if(i < n-3 && s.substr(i, 4) == "TERA"){
            pos[0].push_back(i);
        }
        if(i < n-2 && (s.substr(i, 3) == "TER" || s.substr(i, 3) == "ERA")){
            pos[1].push_back(i);
        }
        if(i < n-1 && (s.substr(i, 2) == "TE" || s.substr(i, 2) == "ER" || s.substr(i, 2) == "RA")){
            pos[2].push_back(i);
        }
        {
            pos[3].push_back(i);
        }
    }

    vector<int> used(n);
    rep(k, 0, 4){
        for(auto l: pos[k]){
            bool ok = true;
            rep(i, l, l+sz[k]){
                if(used[i]) ok = false;
            }
            if(ok){
                ans += score[k];
                rep(i, l, l+sz[k]){
                    used[i] = true;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}