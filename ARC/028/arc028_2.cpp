#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc028/tasks/arc028_2

int main(){
    int n, k; cin >> n >> k;
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];

    priority_queue<pii> que;
    vector<int> y = x;
    sort(y.begin(), y.begin()+k);
    rep(i, 0, k){
        if(x[i] <= y[k-1]){
            que.push({x[i], i+1});
        }
    }

    cout << que.top().second << endl;
    rep(i, k, n){
        pii kth = que.top();
        if(kth.first > x[i]){
            que.pop();
            que.push({x[i], i+1});
        }
        cout << que.top().second << endl;
    }
    
    return 0;
}