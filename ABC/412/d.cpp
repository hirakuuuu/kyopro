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
    int ans = IINF;
    vector<vector<int>> edge(n, vector<int>(n));
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    rep(k, 0, 1<<n){
        vector<int> s, t;
        rep(j, 0, n){
            if((k>>j)&1) s.push_back(j);
            else t.push_back(j);
        }
        if(s.size() == 1 || s.size() == 2 || t.size() == 1 || t.size() == 2) continue;
        if(s.empty()) swap(s, t);

        int l = s.size();
        int cnt1 = IINF, cnt2 = IINF;
        if(t.empty()) cnt2 = 0;
        do{
            int cnt = 0;
            rep(i, 0, l){
                if(edge[s[i]][s[(i+1)%l]]) continue;
                cnt++;
            }
            chmin(cnt1, cnt);
        }while(next_permutation(s.begin(), s.end()));
        l = t.size();
        do{
            int cnt = 0;
            rep(i, 0, l){
                if(edge[t[i]][t[(i+1)%l]]) continue;
                cnt++;
            }
            chmin(cnt2, cnt);
        }while(next_permutation(t.begin(), t.end()));
        // cout << cnt1 << ' ' << cnt2 << endl;
        int tmp = m-(((int)s.size())-cnt1)-(((int)t.size())-cnt2);
        chmin(ans, tmp+cnt1+cnt2);
    }
    cout << ans << endl;
    
    return 0;
}