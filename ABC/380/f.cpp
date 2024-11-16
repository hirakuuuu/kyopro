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
    int n, m, l; cin >> n >> m >> l;
    vector<int> a(n), b(m), c(l);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, l) cin >> c[i];

    // 高橋: 0, 青木: 1, 場: 2.
    int tot = n+m+l;
    vector<int> d;
    rep(i, 0, n) d.push_back(a[i]);
    rep(i, 0, m) d.push_back(b[i]);
    rep(i, 0, l) d.push_back(c[i]);
    
    int N = 1;
    vector<int> thr(tot, 1);
    rep(i, 0, tot){
        N *= 3;
        if(i > 0) thr[i] = thr[i-1]*3;
    }

    vector<vector<int>> memo(N, vector<int>(2, -1));
    auto f = [&](auto self, int tmp, int t) -> int {
        if(memo[tmp][t] != -1) return memo[tmp][t];
        
        vector<int> bit(tot);
        {
            int tmp_ = tmp;
            rep(i, 0, tot){
                bit[i] = tmp_%3;
                tmp_ /= 3;
            }
        }


        int nxt = tmp;
        int res = 0, cnt = 0;
        rep(i, 0, tot){
            if(bit[i] == t){
                cnt++;
                nxt -= t*thr[i];
                nxt += 2*thr[i];
                res |= (1-self(self, nxt, 1-t));
                rep(j, 0, tot){
                    if(bit[j] == 2 && d[j] < d[i]){
                        nxt -= 2*thr[j];
                        nxt += t*thr[j];
                        res |= (1-self(self, nxt, 1-t));
                        nxt += 2*thr[j];
                        nxt -= t*thr[j];
                    }
                }
                nxt += t*thr[i];
                nxt -= 2*thr[i];
            }
        }
        if(cnt == 0) return memo[tmp][t] = 0;
        return memo[tmp][t] = res;
    };

    int init = 0;
    rep(i, 0, tot){
        if(i < n) init += 0*thr[i];
        else if(i < n+m) init += 1*thr[i];
        else init += 2*thr[i];
    }
    if(f(f, init, 0)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    
    
    return 0;
}