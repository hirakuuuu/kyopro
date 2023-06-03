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
// https://atcoder.jp/contests/code-festival-2014-morning-easy/tasks/code_festival_morning_easy_d

int main(){
    int n, m; cin >> n >> m;
    vector<pii> h(n);
    vector<int> a(m);
    priority_queue<pii, vector<pii>, greater<pii>> que;
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        h[i] = {x, y};
        que.push(h[i]);
    }
    rep(i, 0, m) cin >> a[i];

    sort(a.begin(), a.end());
    sort(h.begin(), h.end());


    int pos_h = 0;
    int ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> que_y;
    rep(i, 0, n){
        // a[i]が入れる部屋があるかどうかを考える
        while(pos_h < m && h[pos_h].first <= a[i]){
            que_y.push({h[pos_h].second, h[pos_h].first});
            pos_h++;
        }

        while(!que_y.empty()){
            pii q = que_y.top(); que_y.pop();
            if(a[i] <= q.first){
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}