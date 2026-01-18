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

    vector<tuple<int, int, string>> query(q);
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            int p; cin >> p; p--;
            query[i] = {t, p, ""};
        }else if(t == 2){
            int p; cin >> p; p--;
            string s; cin >> s;
            query[i] = {t, p, s};
        }else{
            int p; cin >> p; p--;
            query[i] = {t, p, ""};
        }
    }
    string ans, tmp;
    bool server = true;
    int pc = -1;
    rrep(i, q-1, 0){
        auto [t, p, s] = query[i];
        if(server){
            if(t == 3){
                // p の文字列が知りたい
                pc = p;
                server = false;
            }
        }else{
            if(t == 1 && p == pc){
                server = true;
                pc = -1;
            }else if(t == 2 && p == pc){
                reverse(s.begin(), s.end());
                ans += s;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
    return 0;
}