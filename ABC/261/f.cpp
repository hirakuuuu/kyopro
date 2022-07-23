#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc261/tasks/abc261_f

int main(){
    int n; cin >> n;
    vector<int> c(n), x(n), cnt_c(n+1), cnt_pos(n);
    priority_queue<vector<int>> que;
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n){
        que.push({x[i], i, c[i]});
        cnt_pos[i] = cnt_c[c[i]];
        cnt_c[c[i]]++;
    }

    map<int, set<int>> m;
    set<int> deleted_pos;
    int ans = 0, r = n-1;

    while(!que.empty()){
        vector<int> q = que.top(); que.pop();
        int pos = distance(m[q[2]].lower_bound(q[1]), m[q[2]].end());


        int now_pos = q[1]-distance(deleted_pos.begin(), deleted_pos.lower_bound(q[1]));
        // cout << r << " " << now_pos << " " << (cnt_c[q[2]]-1-cnt_pos[q[1]]-pos) << endl;
        ans += r-now_pos-(cnt_c[q[2]]-1-cnt_pos[q[1]]-pos);
        // cout << ans << endl;
        m[q[2]].insert(q[1]);
        deleted_pos.insert(q[1]);
        r--;
    }

    cout << ans << endl;




    
    return 0;
}