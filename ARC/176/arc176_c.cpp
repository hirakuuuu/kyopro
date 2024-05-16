#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    vector<int> p(n, -1);
    vector<int> mx(n, IINF);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--, c[i]--;
        chmin(mx[a[i]], c[i]);
        chmin(mx[b[i]], c[i]);
    }
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        g[c[i]].push_back({a[i], b[i]});
    }
    rrep(i, n-1, 0){
        if(g[i].size() >= 2){
            int v = -1;
            rep(_, 0, 2){
                if(g[i][0].first == g[i][1].first || g[i][0].first == g[i][1].second){
                    v = g[i][0].first;
                }
                swap(g[i][0].first, g[i][0].second);
            }
            if(v == -1){
                cout << 0 << endl;
                return 0;
            }
            rep(j, 2, g[i].size()){
                if(g[i][j].first != v && g[i][j].second != v){
                    cout << 0 << endl;
                    return 0;
                }
            }
            p[v] = i;
        }else if(g[i].size() == 1){
            if(p[g[i][0].first] != -1 && p[g[i][0].second] != -1){
                cout << 0 << endl;
                return 0;
            }
            

        }else{

        }
    }
    rep(i, 0, m){
        if(p[a[i]] != -1 && p[b[i]] != -1 && max(p[a[i]], p[b[i]]) != c[i]){
            cout << 0 << endl;
            return 0;
        }
        if(mx[a[i]] < c[i] && mx[b[i]] < c[i]){
            cout << 0 << endl;
            return 0;
        }else if(mx[a[i]] < c[i] && mx[b[i]] == c[i]){
            p[b[i]] = c[i]; 
        }else if(mx[b[i]] < c[i] && mx[a[i]] == c[i]){
            p[a[i]] = c[i];
        }
    }
    // 重複していたらアウト
    vector<int> cnt(n);
    rep(i, 0, n){
        if(p[i] >= 0) cnt[p[i]]++;
    }
    rep(i, 0, n){
        if(cnt[i] >= 2){
            cout << 0 << endl;
            return 0;
        }
    }


    rep(i, 0, n){
        cout << p[i] << ' ';
    }
    cout << endl;
    
    return 0;
}