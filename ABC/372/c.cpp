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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    map<string, int> id;
    int cnt = 0;
    rep(i, 0, 26) rep(j, 0, 26) rep(k, 0, 26){
        string t;
        t += (char)'A'+i;
        t += (char)'A'+j;
        t += (char)'A'+k;
        id[t] = cnt++;
    }

    vector<int> c(26*26*26);
    rep(i, 0, n-2){
        c[id[s.substr(i, 3)]]++;
    }
    int abc = id["ABC"];
    while(q--){
        int x; cin >> x; x--;
        char C; cin >> C;
        {
            rep(i, max(0, x-2), x+1){
                if(i+2 >= n) continue;
                c[id[s.substr(i, 3)]]--;
            }
        }
        s[x] = C;
        {
            rep(i, max(0, x-2), x+1){
                if(i+2 >= n) continue;
                c[id[s.substr(i, 3)]]++;
            }
        }
        cout << c[abc] << endl;
    }
    
    return 0;
}