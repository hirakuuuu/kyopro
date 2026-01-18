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
    vector<int> acc_b(n+1);
    vector<vector<int>> nxt(n, vector(1001, -1));
    vector<vector<int>> result(n+1, vector(1001, -1));
    iota(result[n].begin(), result[n].end(), 0);
    rep(i, 1, n+1){
        int p, a, b; cin >> p >> a >> b;
        acc_b[i] = acc_b[i-1]+b;
        rep(j, 0, 1001){
            if(p >= j){
                nxt[i-1][j] = j+a;
            }else{
                nxt[i-1][j] = max(j-b, 0);
            }
        }
    }

    auto f = [&](auto self, int pos, int val) -> int {
        if(result[pos][val] != -1) return result[pos][val];
        return result[pos][val] = self(self, pos+1, nxt[pos][val]);
    };

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(x <= 1000){
            cout << f(f, 0, x) << endl;
        }else{
            int pos = lower_bound(acc_b.begin(), acc_b.end(), x-1000)-acc_b.begin();
            if(pos == n+1){
                cout << x-acc_b[n] << endl;
            }else{
                cout << f(f, pos, max(0, x-acc_b[pos])) << endl; 
            }
        }
    }
    
    return 0;
}