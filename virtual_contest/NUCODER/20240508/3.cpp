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
    int n; cin >> n;
    vector<vector<int>> a(2*n, vector<int>(2*n, -1));
    rep(i, 0, 2*n){
        rep(j, i+1, 2*n){
            cin >> a[i][j];
        }
    }
    vector<int> p(2*n), cnt(n);
    auto f = [&](auto self, int pos, int used) -> int {
        if(pos == 2*n){
            int ans = 0;
            vector<int> l(n, -1);
            rep(i, 0, 2*n){
                if(l[p[i]] != -1) ans ^= a[l[p[i]]][i];
                else l[p[i]] = i;
            }
            return ans;
        }
        int res = 0;
        rep(i, 0, min(n, used+1)){
            if(cnt[i] == 2) continue;
            cnt[i]++;
            p[pos] = i;
            chmax(res, self(self, pos+1, max(used, i+1)));
            cnt[i]--;
        }
        return res;
    };
    cout << f(f, 0, 0) << endl;

    
    return 0;
}