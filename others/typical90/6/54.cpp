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

/*
*/


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> r(m), a(n);
    rep(i, 0, m){
        int k; cin >> k;
        rep(j, 0, k){
            int c; cin >> c;
            c--;
            r[i].push_back(c);
            a[c].push_back(i);
        }
    }

    vector<int> ans(n, -1), mi(m, -1);
    ans[0] = 0;
    queue<int> que;
    for(auto aa: a[0]){
        que.push(aa);
        mi[aa] = 0;
    }
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto c: r[q]){
            if(ans[c] == -1){
                ans[c] = mi[q]+1;
                for(auto aa: a[c]){
                    if(mi[aa] == -1){
                        mi[aa] = ans[c];
                        que.push(aa);
                    }
                }
            }
        }
    }
    rep(i, 0, n){
        cout << ans[i] << '\n';
    }




    return 0;
}