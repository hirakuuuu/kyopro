#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    int n, ka, kb; cin >> n >> ka >> kb;
    vector<int> a(ka), b(kb);
    rep(i, 0, ka) cin >> a[i], a[i]--;
    rep(i, 0, kb) cin >> b[i], b[i]--;

    vector<int> dist_from_a(n, IINF);
    {
        queue<int> que;
        rep(i, 0, ka) que.push(a[i]), dist_from_a[a[i]] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            if(q < n-1 && dist_from_a[q+1] == IINF){
                dist_from_a[q+1] = dist_from_a[q]+1;
                que.push(q+1);
            }
            if(0 < q && dist_from_a[q-1] == IINF){
                dist_from_a[q-1] = dist_from_a[q]+1;
                que.push(q-1);
            }
        }
    }
    vector<int> dist_from_b(n, IINF);
    {
        queue<int> que;
        rep(i, 0, kb) que.push(b[i]), dist_from_b[b[i]] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            if(q < n-1 && dist_from_b[q+1] == IINF){
                dist_from_b[q+1] = dist_from_b[q]+1;
                que.push(q+1);
            }
            if(0 < q && dist_from_b[q-1] == IINF){
                dist_from_b[q-1] = dist_from_b[q]+1;
                que.push(q-1);
            }
        }
    }

    int dist_a_b = IINF;
    rep(i, 0, kb){
        chmin(dist_a_b, dist_from_a[b[i]]);
    }
    
    int q; cin >> q;
    while(q--){
        int s, t; cin >> s >> t; s--, t--;
        ll ans = IINF;
        chmin(ans, abs(s-t));
        chmin(ans, dist_from_a[s]+dist_from_a[t]);
        chmin(ans, dist_from_b[s]+dist_from_b[t]);
        chmin(ans, dist_from_a[s]+dist_a_b+dist_from_b[t]);
        chmin(ans, dist_from_b[s]+dist_a_b+dist_from_a[t]);
        cout << ans << '\n';
    }

    return 0;
}