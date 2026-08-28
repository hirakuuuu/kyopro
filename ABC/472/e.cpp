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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(m), b(m);
        vector<vector<int>> g(n);
        rep(i, 0, m){
            cin >> a[i] >> b[i]; a[i]--, b[i]--;
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
        vector<int> c(n, -1), pre(n, -1);
        c[0] = 0;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(c[nq] != -1) continue;
                c[nq] = 1-c[q];
                pre[nq] = q;
                que.push(nq);
            }
        }

        bool f = false;
        vector<int> ans;        
        rep(i, 0, m){
            if(f) break;
            if(c[a[i]] == c[b[i]]){
                f = true;
                vector<int> da(n, IINF), db(n, IINF);
                int pos = a[i];
                int now = 0;
                while(pos != -1){
                    da[pos] = now++; 
                    pos = pre[pos];
                }
                pos = b[i];
                now = 0;
                while(pos != -1){
                    db[pos] = now++; 
                    pos = pre[pos];
                }
                now = IINF;
                int r = -1;
                rep(j, 0, n){
                    if(now > da[j]+db[j]){
                        r = j;
                        now = da[j]+db[j];
                    }
                }
                assert(r != -1);



                vector<int> vec;
                pos = a[i];
                while(pos != r){
                    vec.push_back(pos);
                    pos = pre[pos];
                }
                vec.push_back(r);
                for(auto vv: vec) ans.push_back(vv);
                pos = b[i];
                vec.clear();
                while(pos != r){
                    vec.push_back(pos);
                    pos = pre[pos];
                }
                reverse(vec.begin(), vec.end());
                for(auto vv: vec) ans.push_back(vv);
            }
        }

        if(!f){
            cout << -1 << endl;
        }else{
            cout << ans.size() << endl;
            for(auto aa: ans) cout << aa+1 << ' ';
            cout << endl;
        }



    }
    
    return 0;
}