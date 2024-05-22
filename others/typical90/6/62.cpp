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
逆から考えると、今行える操作が今後の操作の仕方によって行えなくなることは無い
つまり、貪欲法が通る
*/

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> g(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    queue<int> que;
    vector<pair<int, int>> d(n, {-1, -1});
    rep(i, 0, n){
        if(a[i] == i || b[i] == i){
            d[i] = {0, i};
            que.push(i);
        }
        g[a[i]].push_back(i);
        g[b[i]].push_back(i);
    }

    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(d[nq].first != -1) continue;
            d[nq] = {d[q].first+1, nq};
            que.push(nq);
        }
    }
    sort(d.rbegin(), d.rend());
    if(d.back().first == -1){
        cout << -1 << endl;
    }else{
        for(auto [_, ans]: d){
            cout << ans+1 << endl;
        }
    }

    return 0;
}