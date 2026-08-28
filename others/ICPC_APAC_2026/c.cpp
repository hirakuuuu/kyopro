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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> u(m), v(m);
    map<pair<int, int>, int> id;
    rep(i, 0, m){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        id[{u[i], v[i]}] = i;
        id[{v[i], u[i]}] = i;
    }
    vector<int> s(n);
    vector<int> rev_s(n);
    rep(i, 0, n) cin >> s[i], s[i]--, rev_s[s[i]] = i;
    rep(i, 0, n){
        sort(g[i].begin(), g[i].end(), [&](int a, int b){
            return rev_s[a] < rev_s[b];
        });
    }

    vector<int> p(n);
    vector<int> seen(n);
    vector<int> inorder;
    auto f = [&](auto self, int pos, int pre) -> void {
        inorder.push_back(pos);
        seen[pos] = 1;
        p[pos] = pre;
        for(auto nxt: g[pos]){
            if(pre == nxt) continue;
            if(seen[nxt]) continue;
            self(self, nxt, pos);
        }
        return;
    };
    f(f, 0, -1);
    if(s != inorder){
        cout << "impossible" << endl;
        return 0;
    }

    vector<vector<int>> tree(n);
    rep(i, 1, n){
        tree[p[i]].push_back(i);
    }
    rep(i, 0, n){
        sort(tree[i].begin(), tree[i].end(), [&](int ti, int tj){
            return rev_s[ti] < rev_s[tj];
        });
    }
    vector<ll> w(m, 1);
    rep(i, 0, n){
        int tmp = 1000000+10*tree[i].size();
        for(auto c: tree[i]){
            w[id[{i, c}]] = tmp;
            tmp -= 2;
        }
    }
    rep(i, 0, m){
        cout << w[i] << ' ';
    }
    cout << endl;

    return 0;
}