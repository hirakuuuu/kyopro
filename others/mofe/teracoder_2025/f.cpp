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

    vector<ll> pre(n, -1);
    vector<ll> fact(n, -1);
    queue<int> que;
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            int a, b, c; cin >> a >> b >> c;
            a--;
            pre[a] = b+c;
            que.push(a);
        }else{
            int b, k; cin >> b >> k;
            rep(_, 0, k){
                int nq = que.front(); que.pop();
                fact[nq] = b;
            }
        }
    }

    rep(i, 0, n){
        if(pre[i] > fact[i]){
            cout << "early" << endl;
        }else if(pre[i] < fact[i]){
            cout << "late" << endl;
        }else{
            cout << "just" << endl;
        }
    }
    return 0;
}