#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc259/tasks/abc259_d

vector<ll> x(3005), y(3005), r(3005);

bool on_circle(ll cx, ll cy, int i){
    return (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy) == r[i]*r[i];
}

int main(){
    int n; cin >> n;
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

    queue<int> que;
    vector<bool> seen(n, false);
    rep(i, 0, n){
        cin >> x[i] >> y[i] >> r[i];
    }

    rep(i, 0, n){
        if(on_circle(sx, sy, i)){
            que.push(i);
            seen[i] = true;
        }
    }

    vector<vector<int>> interact(n);

    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            ll cdist = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if((r[i]-r[j])*(r[i]-r[j]) <= cdist and cdist <= (r[i]+r[j])*(r[i]+r[j])){
                interact[i].push_back(j);
            }
        }
    }
    bool f = false;

    while(!que.empty()){
        int q = que.front(); que.pop();
        if(on_circle(tx, ty, q)){
            f = true;
            break;
        }
        for(auto nq: interact[q]){
            if(seen[nq]) continue;
            seen[nq] = true;
            que.push(nq);
        }
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;



    
    return 0;
}