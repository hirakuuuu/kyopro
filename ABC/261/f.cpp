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

void add(vector<int> &bit, int pos, int val){
    while(pos < bit.size()){
        bit[pos] += val;
        pos += pos&(-pos);
    }
}

int get(vector<int> &bit, int pos){
    int ans = 0;
    while(pos > 0){
        ans += bit[pos];
        pos -= pos&(-pos);
    }
    return ans;
}

int main(){
    int n; cin >> n;
    vector<int> c(n), x(n);
    map<int, vector<int>> m;
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n){
        cin >> x[i];
        m[c[i]].push_back(x[i]);
    }

    vector<int> bit(n+1);

    ll cost = 0;

    for(int i = n-1; i >= 0; i--){
        add(bit, x[i], 1);
        cost += get(bit, x[i]-1);
    }

    for(int i = n-1; i >= 0; i--){
        add(bit, x[i], -1);
    }


    rep(i, 1, n+1){
        for(int j = m[i].size()-1; j >= 0; j--){
            add(bit, m[i][j], 1);
            cost -= get(bit, m[i][j]-1);
        }
        for(int j = m[i].size()-1; j >= 0; j--){
            add(bit, m[i][j], -1);
        }
    }

    cout << cost << endl;






    
    return 0;
}