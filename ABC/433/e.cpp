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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> x(n), y(m);
        vector<int> rev_r(n*m+1, -1);
        vector<int> rev_c(n*m+1, -1);
        bool ok = true;
        rep(i, 0, n){
            cin >> x[i];
            if(rev_r[x[i]] != -1) ok = false;
            rev_r[x[i]] = i;
        }
        rep(i, 0, m){
            cin >> y[i];
            if(rev_c[y[i]] != -1) ok = false;
            rev_c[y[i]] = i;
        }

        if(rev_r[n*m] == -1 || rev_c[n*m] == -1) ok = false;
        if(!ok){
            cout << "No" << endl;
            continue;
        }

        vector<int> seen_r(n), seen_c(m);
        set<int> used_r, used_c;
        vector<vector<int>> a(n, vector<int>(m, -1));

        vector<int> rest;
        queue<pair<int, int>> que;
        rrep(i, n*m, 1){
            // cout << i << endl;
            if(rev_r[i] != -1 && rev_c[i] != -1){
                if(seen_r[rev_r[i]] || seen_c[rev_c[i]]){
                    ok = false;
                    break;
                }
                a[rev_r[i]][rev_c[i]] = i;
                seen_r[rev_r[i]] = 1;
                seen_c[rev_c[i]] = 1;
                for(auto rr: used_r) que.push({rr, rev_c[i]});
                for(auto cc: used_c) que.push({rev_r[i], cc});
                used_r.insert(rev_r[i]);
                used_c.insert(rev_c[i]);
                // able[rev_r[i]].erase(rev_c[i]);
            }else if(rev_c[i] != -1){
                if(seen_c[rev_c[i]] || used_r.empty()){
                    ok = false;
                    break;
                }
                a[*used_r.begin()][rev_c[i]] = i;
                seen_c[rev_c[i]] = 1;
                for(auto rr: used_r) que.push({rr, rev_c[i]});
                used_c.insert(rev_c[i]);
            }else if(rev_r[i] != -1){
                if(seen_r[rev_r[i]] || used_c.empty()){
                    ok = false;
                    break;
                }
                a[rev_r[i]][*used_c.begin()] = i;
                seen_r[rev_r[i]] = 1;
                for(auto cc: used_c) que.push({rev_r[i], cc});
                used_r.insert(rev_r[i]);
            }else{
                if(que.empty()){
                    ok = false;
                    break;
                }
                auto [r, c] = que.front(); que.pop();
                while(!que.empty() && a[r][c] != -1){
                    r = que.front().first;
                    c = que.front().second;
                    que.pop();
                }
                if(a[r][c] != -1){
                    ok = false;
                    break;
                }
                a[r][c] = i;
            }
            // rep(k, 0, n){
            //     rep(j, 0, m){
            //         cout << a[k][j] << ' ';
            //     }
            //     cout << endl;
            // }
        }
        
        rep(i, 0, n) rep(j, 0, m){
            if(a[i][j] == -1) ok = false;
        }
        if(!ok){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
            rep(i, 0, n){
                rep(j, 0, m){
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }

    }
    return 0;
}