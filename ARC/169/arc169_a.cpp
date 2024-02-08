#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc169/tasks/arc169_a

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> p(n);
    vector<vector<ll>> rev_p(n);
    rep(i, 1, n){
        cin >> p[i];
        p[i]--;
        rev_p[p[i]].push_back(i);
    }
    queue<ll> que;
    que.push(0);
    vector<ll> dist(n);
    dist[0] = 0;
    ll max_d = 0;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: rev_p[q]){
            dist[nq] = dist[q]+1;
            chmax(max_d, dist[nq]);
            que.push(nq);
        }
    }
    vector<ll> sum(max_d+1);
    rep(i, 0, n){
        sum[dist[i]] += a[i];
    }
    rrep(i, max_d, 0){
        if(sum[i] > 0){
            cout << '+' << endl;
            return 0;
        }else if(sum[i] < 0){
            cout << '-' << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}