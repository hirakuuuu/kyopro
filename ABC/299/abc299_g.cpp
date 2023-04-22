#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc299/tasks/abc299_f

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<int>> pos(m+1);
    rep(i, 1, n+1) pos[a[i]].push_back(i);

    vector<pii> right(m);
    rep(i, 1, m+1){
        right[i-1] = {pos[i].back(), i};
    }
    sort(right.begin(), right.end());
    // rep(i, 0, m){
    //     cout << right[i].first << ' ' << right[i].second << endl;
    // }

    int l = 1;
    vector<bool> used(m+1);
    vector<int> ans;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    rep(i, 0, m){
        if(used[right[i].second]) continue;
        rep(j, l, right[i].first+1){
            que.push({a[j], j});
        }
        int r = l-1;
        while(!que.empty()){
            pii q = que.top(); que.pop();
            if(used[q.first] or q.second < r) continue;
            used[q.first] = true;
            r = q.second;
            ans.push_back(q.first);
        }
        l = right[i].first+1;
    }

    rep(i, 0, m) cout << ans[i] << ' ';
    cout << endl;

    
    return 0;
}