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
    int q; cin >> q;
    vector<int> pre(q+1, -IINF);
    vector<int> nxt(q+1, -IINF);
    pre[0] = -1;
    nxt[0] = -1;
    rep(i, 1, q+1){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            pre[i] = x;
            nxt[i] = nxt[x];
            nxt[x] = i;
            if(nxt[i] != -1) pre[nxt[i]] = i;
        }else{
            int x, y; cin >> x >> y;
            int px = x, nx = x;
            while(px != y && nx != y){
                // cout << px << ' ' << nx << endl;
                if(px != -1) px = pre[px];
                if(nx != -1) nx = nxt[nx];
            }
            ll sum = 0;
            if(px == y){
                int tmp = nxt[y];
                while(tmp != x){
                    sum += (ll)tmp;
                    tmp = nxt[tmp];
                }
                nxt[y] = x;
                pre[x] = y;
            }else{
                int tmp = pre[y];
                while(tmp != x){
                    sum += (ll)tmp;
                    tmp = pre[tmp];
                }
                nxt[x] = y;
                pre[y] = x;
            }
            cout << sum << endl;
        }

    }
    return 0;
}