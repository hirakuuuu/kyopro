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
    vector<int> a(n);
    vector<vector<int>> v(n);
    rep(i, 0, n){
        cin >> a[i]; a[i]--;
        v[a[i]].push_back(i);
    }

    vector<int> p(n);
    rep(i, 0, n){
        int sz = v[i].size();
        rep(j, 0, sz){
            p[v[i][j]] = v[i][(j-1+sz)%sz];
        }
    }

    vector<int> s(n, 0), t(n, 1);
    queue<int> sq, tq;
    rep(i, 0, n){
        sq.push(i);
        tq.push(i);
    }
    while(!sq.empty()){
        int i = sq.front();
        int j = tq.front();
        if(j == p[i]){
            s.push_back(1);
            t.push_back(0);
            sq.pop();
            tq.pop();
        }else{
            s.push_back(0);
            t.push_back(0);
            sq.pop();
            sq.push(i);
        }
    }

    cout << s.size() << endl;
    rep(i, 0, s.size()) cout << s[i];
    cout << endl;
    rep(i, 0, t.size()) cout << t[i];
    cout << endl;

    vector<vector<int>> gs(2);
    vector<vector<int>> gt(2);
    rep(i, 0, s.size()){
        gs[s[i]].push_back(i);
        gt[t[i]].push_back(i);
    }

    rep(k, 0, 2){
        rep(i, 0, gs[k].size()){
            if(gs[k][i] < n && gt[k][i] < n){
                assert(a[gs[k][i]] == a[gt[k][i]]);
            }
        }
    }



    
    return 0;
}